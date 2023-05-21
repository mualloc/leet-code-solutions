class Solution {
public:
    // TC: O(n*n!)
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
            if(isValid2(row, col, curr)){
                curr[row][col] = 'Q';
                /*usedLeftDiag.insert(row - col);
                usedRightDiag.insert(row + col);
                usedCol.insert(col);*/
                solveNQueensHelper(n, row + 1, curr, result);
                curr[row][col] = '.';
                /*usedLeftDiag.erase (row - col);
                usedRightDiag.erase (row + col);
                usedCol.erase (col);*/
            }
        }
    }

    bool isValid(int row, int col, const vector<string>& board){
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board.size(); ++j){
                if('Q' == board[i][j] && (row + col == i + j || row - col == i - j || col == j)) return false;
            }
        }
        return true;
    }

    bool isValid2(int row, int col, const vector<string>& board){
        for(int i = 0; i < board.size(); ++i){
            // Check column-wise
            if('Q' == board[i][col]) return false;
            // Check up-left
            if(row - i - 1 >= 0 && col - i - 1 >= 0){
                if('Q' == board[row - i - 1][col - i - 1]) return false;
            }
            // Check up-right
            if(row - i - 1 >= 0 && col + i + 1 < board.size()){
                if('Q' == board[row - i - 1][col + i + 1]) return false;
            }
            //No need to traverse more since the lower rows below current row will always be safe.
            // Check down-right
            /*if(row + i + 1 < board.size() && col + i + 1 < board.size()){
                if('Q' == board[row + i + 1][col + i + 1]) return false;
            }*/
            // Check down-left
            /*if(row + i + 1 < board.size() && col - i - 1 >= 0){
                if('Q' == board[row + i + 1][col - i - 1]) return false;
            }*/
        }
        return true;
    }

    bool isValid3(int row, int col, const vector<string>& board){
        if(usedLeftDiag.end() == usedLeftDiag.find(row - col) && usedRightDiag.end() == usedRightDiag.find(row + col) && usedCol.end() == usedCol.find(col)) return true;
        else return false;
    }

    unordered_set<int> usedLeftDiag;
    unordered_set<int> usedRightDiag;
    unordered_set<int> usedCol;
};
