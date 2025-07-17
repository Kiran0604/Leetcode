class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), level = 0;
        vector<int> res;
        while (level < m) {
            if (level % 2 == 0) {
                for (int i = 0; i < n; i++) {
                    if (i % 2 == 0)
                        res.push_back(grid[level][i]);
                }
            } else {
                for (int i = n - 1; i >= 0; i--) {
                    if (i % 2 == 1)
                        res.push_back(grid[level][i]);
                }
            }
            level++;
        }
        return res;
    }
};
