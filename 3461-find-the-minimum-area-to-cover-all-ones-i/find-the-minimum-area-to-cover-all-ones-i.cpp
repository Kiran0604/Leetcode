class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), minr = 999, minc = 999,
            maxr = 0, maxc = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c]) {
                    minr = min(minr, r);
                    maxr = max(maxr, r);
                    minc = min(minc, c);
                    maxc = max(maxc, c);
                }
            }
        }
        return (maxr - minr + 1) * (maxc - minc + 1);
    }
};