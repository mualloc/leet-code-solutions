class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solveNQueensHelper(n, 0, board, result);
        return result;
    }

private:
    void solveNQueensHelper(const int n, int row, vector<string>& curr, vector<vector<string>>& result){
        if(row == n) {
            result.push_back(curr);
            return;
        }
        for(int col = 0; col < n; ++col){
            if(isValid(row, col, curr)){
                curr[row][col] = 'Q';
                solveNQueensHelper(n, row + 1, curr, result);
                curr[row][col] = '.';
            }
        }
    }

    bool isValid(int row, int col, const vector<string>& board){
        for(int i = 0; i < board.size(); ++i){
            // Check column-wise and row-wise
            if('Q' == board[i][col] || 'Q' == board[row][i]) return false;
            // Check down-right
            if(row + i + 1 < board.size() && col + i + 1 < board.size()){
                if('Q' == board[row + i + 1][col + i + 1]) return false;
            }
            // Check up-left
            if(row - i - 1 >= 0 && col - i - 1 >=0){
                if('Q' == board[row - i - 1][col - i - 1]) return false;
            }
            // Check up-right
            if(row - i - 1 >= 0 && col + i + 1 < board.size()){
                if('Q' == board[row - i - 1][col + i + 1]) return false;
            }
            // Check down-left
            if(row + i + 1 < board.size() && col - i - 1 >=0){
                if('Q' == board[row + i + 1][col - i - 1]) return false;
            }
        }
        return true;
    }
};