class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> row;
            for (int j = 0; j < 9; ++j) {
                char ele = board[i][j];
                if (ele == '.') continue;
                if (row.find(ele) != row.end()) return false;
                row.insert(ele);
            }
        }

        // Check columns
        for (int j = 0; j < 9; ++j) {
            unordered_set<char> col;
            for (int i = 0; i < 9; ++i) {
                char ele = board[i][j];
                if (ele == '.') continue;
                if (col.find(ele) != col.end()) return false;
                col.insert(ele);
            }
        }

        // Check 3x3 sub-boxes
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                unordered_set<char> box;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        char ele = board[boxRow + i][boxCol + j];
                        if (ele == '.') continue;
                        if (box.find(ele) != box.end()) return false;
                        box.insert(ele);
                    }
                }
            }
        }

        return true;
    }
};
