class Solution {
public:
    // SC: O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        bool fr = false;       // Does first row has 0?
        bool fc = false;       // Does first column has 0?
        
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(0 == matrix[i][j]){
                    if(0 == i) fr = true;
                    if(0 == j) fc = true;
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < matrix.size(); ++i){
            for(int j = 1; j < matrix[0].size(); ++j){
                if(0 == matrix[i][0] || 0 == matrix[0][j]) matrix[i][j] = 0;
            }
        }   
         
        if(fc) for(int i = 0; i < matrix.size(); ++i) matrix[i][0] = 0;
        if(fr) for(int j = 0; j < matrix[0].size(); ++j) matrix[0][j] = 0;
    }
};


class Solution2 {
public:
    // SC: O(m + n)
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> rowZeros(matrix.size(), false);
        vector<bool> colZeros(matrix[0].size(), false);
        
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){ 
                if(0 == matrix[i][j]) rowZeros[i] = colZeros[j]= true;
            }
        }
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(rowZeros[i] || colZeros[j]) matrix[i][j] = 0;             
            }
        }
    }
};


class Solution3 {
public:
    // SC: O(m * n)
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> copy = matrix;
        
        for(int i = 0; i < copy.size(); ++i){
            for(int j = 0; j < copy[0].size(); ++j){
                if(0 == copy[i][j]){
                    for(int r = 0; r < copy.size(); ++r) matrix[r][j] = 0;
                    for(int c = 0; c < copy[0].size(); ++c) matrix[i][c] = 0;
                }
            }
        }
    }
};