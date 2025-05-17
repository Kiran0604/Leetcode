class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int prev2 = 0;
        int prev1 = 0;
        for (int i = start; i <= end; ++i) {
            int pick = nums[i] + prev2;
            int notPick = prev1;
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: Rob from house 0 to n-2
        int case1 = robRange(nums, 0, n - 2);

        // Case 2: Rob from house 1 to n-1
        int case2 = robRange(nums, 1, n - 1);

        return max(case1, case2);
    }
};
