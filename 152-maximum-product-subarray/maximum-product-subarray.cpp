class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxProd = nums[0]; // Final result
        int currMax = nums[0]; // Max product ending at current position
        int currMin = nums[0]; // Min product ending at current position

        for (int i = 1; i < n; ++i) {
            // If the current number is negative, swap max and min
            if (nums[i] < 0) {
                swap(currMax, currMin);
            }

            currMax = max(nums[i], nums[i] * currMax);
            currMin = min(nums[i], nums[i] * currMin);

            maxProd = max(maxProd, currMax);
        }

        return maxProd;
    }
};
