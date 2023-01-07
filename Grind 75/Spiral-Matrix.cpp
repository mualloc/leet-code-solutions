#define  IS_FINISHED() (result.size() < nRows * nCols)

// A very good solution: https://leetcode.com/problems/spiral-matrix/discuss/20573/A-concise-C++-implementation-based-on-Directions
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int nRows = matrix.size(), nCols = matrix[0].size();
        vector<int> result;
        result.reserve(nRows * nCols);
        
        int left = 0, right = nCols - 1, top = 0, bottom = nRows - 1;
        
        while(left <= right && top <= bottom/*IS_FINISHED()*/){
            for(int j = left; j <= right; ++j) result.push_back(matrix[top][j]);
            ++top;
            for(int i = top; i <= bottom; ++i) result.push_back(matrix[i][right]);
            --right;
            
            if(left > right || top > bottom) break;
            
            for(int j = right; j >= left /*&& IS_FINISHED()*/; --j) result.push_back(matrix[bottom][j]);
            --bottom;
            for(int i = bottom; i >= top /*&& IS_FINISHED()*/; --i) result.push_back(matrix[i][left]);
            ++left; 
        }
        
        return result;
    }
};

/*class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int nRows = matrix.size(), nCols = matrix[0].size();
        vector<int> result;
        result.reserve(nRows * nCols);
        
        int start {0};
        while(nRows > 0 && nCols > 0){
            if(1 == nRows || 1 == nCols){       
                for(int i = 0; i < nRows; i++){
                    for(int j = 0; j < nCols; j++){
                        result.push_back(matrix[i + start][j + start]);
                    }
                }
                break;  // Exit
            } 
            
            int row = start, col = start;
            while(col < nCols + start - 1) result.push_back(matrix[row][col++]);
            while(row < nRows + start - 1) result.push_back(matrix[row++][col]);
            while(col > start) result.push_back(matrix[row][col--]);
            while(row > start) result.push_back(matrix[row--][col]);
            
            nRows -= 2;
            nCols -= 2;
            start++;
        }

        return result;
    }
};*/