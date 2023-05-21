// Very good cache solution: https://leetcode.com/problems/sudoku-solver/solutions/15853/simple-and-clean-solution-c/comments/15881/
class Solution {
public:
    // TC: O(9^81) NOTE: 81 is for number of the initial empty cells
    // SC: O(81)
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(0, 0, board);
    }

private:
    bool solveSudokuHelper(int row, int col, vector<vector<char>>& board) {
        for(int i = row; i < 9; ++i, col = 0){  // Note: Col must be reset here!!!
            for(int j = col; j < 9; ++j){
                if('.' == board[i][j]) {
                    for(char candidate = '1'; candidate <= '9'; ++candidate){
                        if(isValid(i, j, board, candidate)){
                            board[i][j] = candidate;
                            if(true == solveSudokuHelper(i, j + 1, board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(int row, int col, const vector<vector<char>>& board, const char candidate){
        const int row_start = (row / 3) * 3;
        const int col_start = (col / 3) * 3;

        for(int i = 0; i < 9; ++i){
            // Scan square-wise
            if(candidate == board[row_start + i / 3][col_start + i % 3]) return false;
            // Scan row-wise
            if(candidate == board[row][i]) return false;
            // Scan col-wise
            if(candidate == board[i][col]) return false;
        }
        return true;
    }
};