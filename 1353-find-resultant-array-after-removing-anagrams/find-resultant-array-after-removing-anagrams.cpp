class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        string prevKey = "";

        for (const string& word : words) {
            string key = word;
            sort(key.begin(), key.end());

            if (key != prevKey) {
                result.push_back(word);
                prevKey = key;
            }
        }

        return result;
    }
};
