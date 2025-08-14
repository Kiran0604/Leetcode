class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n = a.size(), res = 0;

        for (int i = 0; i < n; i++) {
            res = res ^ a[i];
            res = res ^ (i);
        }
        res = res ^ n;
        return (res);
    }
};
