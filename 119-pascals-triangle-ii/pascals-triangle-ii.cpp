class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> mat;
        for (int i = 0; i <= rowIndex; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    temp.push_back(1);
                else
                    temp.push_back(mat[i - 1][j - 1] + mat[i - 1][j]);
            }
            mat.push_back(temp);
        }
        return mat[rowIndex];
    }
};