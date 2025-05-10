class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int charMap[256] = {0}, start = 0, maxLength = 0;
        for (int end = 0; end < s.size(); ++end) {
            charMap[s[end]]++;
            while (charMap[s[end]] > 1) {
                charMap[s[start]]--;
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};
