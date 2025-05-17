class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1; 
        // Iterate until mid pointer exceeds high pointer
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(&nums[low], &nums[mid]); // Swap 0 to the front
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++; // Just move mid for 1
            } else {
                swap(&nums[mid], &nums[high]); // Swap 2 to the back
                high--;
            }
        }
    }

    void swap(int* a, int* b) {
        int t = *a;
        *a = *b;
        *b = t;
    }
};