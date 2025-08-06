class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;

        for (int i = 1; i < nums.size() - 1; ++i) {
            // Skip equal neighbors
            if (nums[i] == nums[i - 1]) continue;

            int left = i - 1;
            // Move left until a different number is found
            while (left >= 0 && nums[left] == nums[i]) {
                left--;
            }

            int right = i + 1;
            // Move right until a different number is found
            while (right < nums.size() && nums[right] == nums[i]) {
                right++;
            }

            // Check if both neighbors exist
            if (left >= 0 && right < nums.size()) {
                if (nums[i] > nums[left] && nums[i] > nums[right]) {
                    ++count; // Hill
                } else if (nums[i] < nums[left] && nums[i] < nums[right]) {
                    ++count; // Valley
                }
            }
        }

        return count;
    }
};
