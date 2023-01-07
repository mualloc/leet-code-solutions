class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 2;        
        
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[0].size(); col++){
                if(2 == grid[row][col]){
                    DFS(row, col, grid, minutes);
                }
            }
        }
            
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[0].size(); col++){
                minutes = max(minutes, grid[row][col]);
                if(1 == grid[row][col]){
                    return -1;
                }
            }       
        }
        
        return minutes - 2;
    }
        
    void DFS(int row, int col, vector<vector<int>>& grid, int minutes){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return;
        
        if(0 == grid[row][col] || (grid[row][col] > 1 && grid[row][col] < minutes)) return;
        grid[row][col] = minutes;
        minutes++;
        DFS(row + 1, col, grid, minutes);
        DFS(row - 1, col, grid, minutes);
        DFS(row, col + 1, grid, minutes);
        DFS(row, col - 1, grid, minutes);

    }
    
    /*int orangesRotting(vector<vector<int>>& grid) {
        int result = 0;
        int dirs[] = {0, 1, 0, -1, 0};
        queue<pair<int,int>> queue;
        int freshCount = 0;
        
        for(size_t row = 0; row < grid.size(); row++){
            for(size_t col = 0; col < grid[0].size(); col++){
                if(2 == grid[row][col]){
                    queue.push(make_pair(row, col));
                }else if(1 == grid[row][col]) ++freshCount;
            }
        }
        while(false == queue.empty() && freshCount > 0){
            result++;
            int queueSize = queue.size();
            while(queueSize--){
                pair<int,int> coor = queue.front(); queue.pop();
                for(size_t i = 0; i < 4; i++){
                    int nRow = coor.first + dirs[i];        // neighbour row
                    int nCol = coor.second + dirs[i + 1];
                    if(true == isFresh(nRow, nCol, grid)){
                        grid[nRow][nCol] = 2;
                        --freshCount;
                        queue.push(make_pair(nRow, nCol));
                    }                       
                }              
            }
        }
        return 0 == freshCount ? result : -1;  
    }
    
private:
    bool isFresh(int row, int col, const vector<vector<int>>& grid){
        if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && 1 == grid[row][col]) return true;
        return false;
    }*/
};