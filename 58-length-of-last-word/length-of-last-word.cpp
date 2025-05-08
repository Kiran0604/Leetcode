class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0, res = 0;
        for (char c : s) {
            if (c != ' ')
                count++;
            else {
                if(count)
                    res = count;
                count = 0;
            }
        }
        return count > 0 ? count : res;
    }
};