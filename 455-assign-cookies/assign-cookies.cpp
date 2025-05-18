class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; // index for children
        int j = 0; // index for cookies
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++; // child is content
            }
            j++; // move to next cookie
        }
        return i;
    }
};
