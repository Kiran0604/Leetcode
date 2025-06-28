class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> indexed;
        
        // Pair each number with its original index
        for (int i = 0; i < nums.size(); ++i) {
            indexed.push_back({nums[i], i});
        }

        // Sort by value descending to find top k elements
        sort(indexed.begin(), indexed.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        // Take the top k elements
        vector<pair<int, int>> topK(indexed.begin(), indexed.begin() + k);

        // Sort selected elements by original index to maintain order
        sort(topK.begin(), topK.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        // Extract the values
        vector<int> result;
        for (auto &p : topK) {
            result.push_back(p.first);
        }

        return result;
    }
};
