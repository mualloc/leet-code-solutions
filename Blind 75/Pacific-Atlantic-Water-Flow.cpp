class Solution {
public:
    // TC: O(m*n). Explanation: This will happen only when all elements are become equal.
    // SC: O(m*n)
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int nRows = heights.size(), nCols = heights[0].size();
        queue<vector<int>> pQueue, aQueue;
        vector<vector<bool>> pVisited(nRows, vector<bool>(nCols, false));
        vector<vector<bool>> aVisited(nRows, vector<bool>(nCols, false));
        for(int j = 0; j < nCols; j++){
            pQueue.push({0, j}); pVisited[0][j] = true;
            aQueue.push({nRows - 1, j}); aVisited[nRows - 1][j] = true;
        }
        for(int i = 0; i < nRows; i++){
            pQueue.push({i, 0}); pVisited[i][0] = true;
            aQueue.push({i, nCols - 1}); aVisited[i][nCols - 1] = true;
        }
        
        bfs(heights, pQueue, pVisited);
        bfs(heights, aQueue, aVisited);      
                
        vector<vector<int>> result;
        for(int i = 0; i < nRows; ++i){
            for(int j = 0; j < nCols; ++j){
                if(pVisited[i][j] && aVisited[i][j]) result.push_back({i, j});
            }
        }
 
        return result;
    }
    
private:
    void bfs(vector<vector<int>>& heights, queue<vector<int>> & queue, vector<vector<bool>> & visited){
        static const int dir[5] = {0, 1, 0, -1, 0};
        const int nRows = heights.size(), nCols = heights[0].size();

        while(!queue.empty()){
            vector<int> front = queue.front(); queue.pop();
            int row = front[0], col = front[1];
            
            for(int i = 0; i < 4; i++){
                const int nr = row + dir[i];
                const int nc = col + dir[i + 1];
                if(nr < 0 || nr == nRows || nc < 0 || nc == nCols || visited[nr][nc] || heights[nr][nc] < heights[row][col]) continue;
                queue.push({nr, nc}); 
                visited[nr][nc] = true;
            }
        }
    }
};


class Solution2 {
public:
    // Hash function 
    struct hashFunction {
        size_t operator()(const pair<int, int> &x) const{
            return x.first ^ x.second;
        }
    };
    
    // TC: O(m*n). Explanation: This will happen only when all elements are become equal.
    // SC: O(2mn + h) = O(mn) where h is the maximum depth of the recursion. In the worst case, O(h) = O(m*n)
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        unordered_set<pair<int, int>, hashFunction> pacific, atlantic;
        const int nRows = heights.size(), nCols = heights[0].size();
        
        for(int j = 0; j < nCols; j++){
            dfs(0, j, pacific, heights[0][j], heights);
            dfs(nRows - 1, j, atlantic, heights[nRows - 1][j], heights);
        }
        for(int i = 0; i < nRows; i++){
            dfs(i, 0, pacific, heights[i][0], heights);
            dfs(i, nCols - 1, atlantic, heights[i][nCols - 1], heights);
        }
        
        vector<vector<int>> result;
        for(const auto & v : pacific){
            if(atlantic.find(v) != atlantic.end()){
                result.push_back({v.first, v.second});
            }
        }
        return result;
    }

private:
    void dfs(int row, int col, unordered_set<pair<int, int>, hashFunction> & visited, int prevHeight, vector<vector<int>>& heights){
        const int nRows = heights.size(), nCols = heights[0].size();
        if(row < 0 || row == nRows || col < 0 || col == nCols || visited.end() != visited.find(make_pair(row, col)) || prevHeight > heights[row][col]) return;
        
        visited.insert(make_pair(row, col));
        dfs(row + 1, col, visited, heights[row][col], heights);
        dfs(row - 1, col, visited, heights[row][col], heights);
        dfs(row, col + 1, visited, heights[row][col], heights);
        dfs(row, col - 1, visited, heights[row][col], heights);
    }
};