class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxDP(n); // max product ending at index i
        vector<int> minDP(n); // min product ending at index i

        maxDP[0] = nums[0];
        minDP[0] = nums[0];
        int result = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] >= 0) {
                maxDP[i] = max(nums[i], nums[i] * maxDP[i - 1]);
                minDP[i] = min(nums[i], nums[i] * minDP[i - 1]);
            } else {
                maxDP[i] = max(nums[i], nums[i] * minDP[i - 1]);
                minDP[i] = min(nums[i], nums[i] * maxDP[i - 1]);
            }
            result = max(result, maxDP[i]);
        }

        return result;
    }
};
