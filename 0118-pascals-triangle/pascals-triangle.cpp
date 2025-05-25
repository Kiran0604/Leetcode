class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> mat;
        for (int i = 0; i < numRows; i++) {
            vector<int> temp; // Reset temp for each row
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    temp.push_back(1);
                else
                    temp.push_back(mat[i - 1][j - 1] + mat[i - 1][j]);
            }
            mat.push_back(temp);
        }
        return mat;
    }
};
