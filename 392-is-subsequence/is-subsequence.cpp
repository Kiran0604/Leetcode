class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s1=0, n=s.size(), m=t.size(), s2=0,c=0;
        while(s1<=n-1 && s2<=m-1)
        {
            if(s[s1]==t[s2])
            {
                c++;
                s1++;
                s2++;
            }
            else s2++;
        }
        return c==n;
    }
};