class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int dim = matrix.size();
        // First, transpose matrix
        for(int i = 0; i < dim; ++i){
            for(int j = i; j < dim; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Then, swap column-wise
        for(int i = 0; i < dim; ++i){
            for(int j = 0; j < dim / 2; ++j){
                swap(matrix[i][j], matrix[i][dim -1 -j]);
            }
        }
    }
};


class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0, right = matrix.size() -  1;
        
        while(left < right){
            const int top = left, bottom = right;
            
            for(int i = 0; i < right - left; ++i){
                const int topLeft = matrix[top][left + i];
                // Update top left
                matrix[top][left + i] = matrix[bottom - i][left];
                // Update bottom left
                matrix[bottom - i][left] = matrix[bottom][right - i];
                // Update bottom right
                matrix[bottom][right - i] =  matrix[top + i][right];
                // Update top right
                matrix[top + i][right] = topLeft;   
            }
            ++left;
            --right;
        }        
    }
};