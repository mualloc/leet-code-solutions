class Solution {
public:
    // TC: O(R * C * 4^W)
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(true == existHelper(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
    
private:
    bool existHelper(vector<vector<char>>& board, int row, int col, const string & word, int i){
        if(word.size() == i) return true;
        int nRows = board.size(), nCols = board[0].size();
        if(row < 0 || col < 0 || row == nRows || col == nCols || word[i] != board[row][col]) return false;
        
        board[row][col] = 0;
        if(existHelper(board, row + 1, col, word, i + 1) ||
          existHelper(board, row -1, col, word, i + 1) ||
          existHelper(board, row, col + 1, word, i + 1) ||
          existHelper(board, row, col - 1, word, i + 1)) return true;
        
        board[row][col] = word[i];
        return false;
    }
};


class Solution2 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){                    
                if(board[i][j] == word[0]){
                    if(1 == word.size()) return true;
                    visited[i][j] = true;
                    for(int d = 0; d < kDirsSize - 1; ++d){
                        int nr = i + dirs[d], nc = j + dirs[d + 1];
                        if(true == isVisitable(nr, nc, visited)){
                            if(true == existHelper(board, word, 1, nr, nc, visited)) return true;
                        }
					}
                    visited[i][j] = false;
                }
            }
        }     
        return false;
    }
    
private:
    bool existHelper(const vector<vector<char>>& board, const string & word, int start, int row, int col, vector<vector<bool>> & visited) {
        for(int i = row; i < board.size(); ++i){
            for(int j = col; j < board[0].size(); ++j){
                for(int k = start; k < word.size(); ++k){
                    if(board[i][j] == word[k]){
                        if(k == word.size() - 1) return true;
                        visited[i][j] = true;
                        for(int d = 0; d < kDirsSize - 1; ++d){
                            int nr = i + dirs[d], nc = j + dirs[d + 1];
                            if(true == isVisitable(nr, nc, visited)){
                                if(true == existHelper(board, word, k + 1, nr, nc, visited)) return true;
                            }
						}
                        visited[i][j] = false;
                        return false;
					}else {
                        return false;
                    }
				}                
			}
		}
		return false;
	}
    
private:
    bool isVisitable(int row, int col, const vector<vector<bool>> & visited){
        int nRows = visited.size();
        int nCols = visited[0].size();

        if(row < 0 || row >= nRows || col < 0 || col >= nCols || visited[row][col]) return false;
        else return true;
    }
    
    static constexpr int kDirsSize = 5;
    static constexpr char dirs[kDirsSize] = {1, 0, -1, 0, 1};   // asa sol yuk sag  
};