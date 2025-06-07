class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<int> pos[26];
        vector<bool> rm(n, false);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                rm[i] = true;
                for (int c = 0; c < 26; ++c)
                    if (!pos[c].empty()) {
                        rm[pos[c].back()] = true;
                        pos[c].pop_back();
                        break;
                    }
            } else {
                pos[s[i] - 'a'].push_back(i);
            }
        }
        string ans;
        for (int i = 0; i < n; ++i)
            if (!rm[i])
                ans += s[i];
        return ans;
    }
};
