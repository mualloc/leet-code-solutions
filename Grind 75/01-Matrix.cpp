class Solution {
public:
    
    // Excellent explanation: https://leetcode.com/problems/01-matrix/discuss/1369741/C%2B%2BJavaPython-BFS-DP-solutions-with-Picture-Clean-and-Concise-O(1)-Space
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int nRows = mat.size(), nCols = mat[0].size();
        int INF = nCols + nRows;
        
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                if(0 != mat[i][j]){
                    int top = INF, left = INF;
                    if(i > 0){ top = mat[i - 1][j];}
                    if(j > 0){ left = mat[i][j - 1];}
                    mat[i][j] = min(top,left) + 1;                    
                }
            }
        }
        
        for(int i = nRows - 1; i >= 0; i--){
            for(int j = nCols - 1; j >= 0; j--){
                if(0 != mat[i][j]){
                    int bottom = INF, right = INF;
                    if(i < nRows - 1){ bottom = mat[i + 1][j];}
                    if(j < nCols - 1){ right = mat[i][j + 1];}
                    mat[i][j] = min(mat[i][j], min(bottom,right) + 1);                    
                }
            }
        }
        return mat;
    }
        
    /*vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int nRows = mat.size();
        int nCols = mat[0].size();
        queue<pair<int,int>> queue;
        int dirs[] = {0, 1, 0, -1, 0};
        
        for(size_t i = 0; i < nRows; i++){
            for(size_t j = 0; j < nCols; j++){
                if(0 == mat[i][j]){
                    queue.emplace(i,j);
                }else{
                    mat[i][j] = -1;  // unprocessed
                }
            }
        }
        
        while(false == queue.empty()){
            pair<int,int> coor = queue.front(); queue.pop();
            int row = coor.first;
            int col = coor.second;
            for(size_t i= 0; i < 4; i++){
                int neighRow = row + dirs[i];
                int neighCol = col + dirs[i+1];
                if(neighRow < 0 || neighRow >= nRows || neighCol < 0 || neighCol >= nCols || -1 != mat[neighRow][neighCol]){
                    continue;
                }else{
                    mat[neighRow][neighCol] = mat[row][col] + 1;
                    queue.emplace(neighRow,neighCol);
                }
            }
        }           
        return mat;        
    }*/
};