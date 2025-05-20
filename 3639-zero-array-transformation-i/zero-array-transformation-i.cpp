class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0); // difference array

        // Apply range updates in O(1)
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            diff[l] -= 1;
            if (r + 1 < n) diff[r + 1] += 1;
        }

        // Apply prefix sum to update nums efficiently
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            curr += diff[i];
            nums[i] += curr;
            if (nums[i] > 0)
                return false;
        }

        return true;
    }
};
