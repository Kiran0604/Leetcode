class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int prev = groups[0];
        res.push_back(words[0]);
        for (int i = 1; i < groups.size(); i++) {
            if (groups[i] != prev) {
                res.push_back(words[i]);
                prev = groups[i];
            }
        }
        return res;
    }
};