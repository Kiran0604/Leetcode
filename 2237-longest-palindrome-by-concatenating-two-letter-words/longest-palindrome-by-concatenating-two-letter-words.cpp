class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        int length = 0;
        bool hasCenter = false;
        for (string& word : words) {
            freq[word]++;
        }
        for (auto& [word, count] : freq) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (word == rev) {
                // Palindromic word like "aa"
                length += (count / 2) * 4;
                if (count % 2)
                    hasCenter = true;
            } else if (freq.find(rev) != freq.end()) {
                int pairs = min(count, freq[rev]);
                length += pairs * 4;
                freq[rev] = 0; // Avoid double-counting
                freq[word] = 0;
            }
        }

        if (hasCenter)
            length += 2; // Add one palindromic word in the center
        return length;
    }
};
