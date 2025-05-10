class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // Stores the number and its index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // Check if the complement is already in the map
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i}; // Return the indices
        }

        // Store the current number with its index
        numMap[nums[i]] = i;
    }
    
    // Return an empty vector if no solution is found (this case shouldn't occur given problem constraints)
    return {};
}
};
