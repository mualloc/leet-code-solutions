class Solution {
/*public:
    // NOTE: This is a DFS solution without recursion
   int numIslands(vector<vector<char>> &grid) {
      int result = 0;
      deque<pair<int, int>> deque;  
      for (size_t i = 0; i < grid.size(); i++) {
         for (size_t j = 0; j < grid[0].size(); j++) {
            if ('1' == grid[i][j]) {
               deque.push_back(make_pair(i, j));
               grid[i][j] = '2';  // Mark as visited
               ++result;
               while (false == deque.empty()) {
                  pair<int, int> coor = deque.back();
                  deque.pop_back();
                  int row = coor.first;
                  int col = coor.second;
                  static int dirs[] = {0, 1, 0, -1, 0};

                  for (int dirIndex = 0; dirIndex < 4; dirIndex++) {
                     int nRow = row + dirs[dirIndex];
                     int nCol = col + dirs[dirIndex + 1];

                     if (true == isValidCell(nRow, nCol, grid)) {
                        grid[nRow][nCol] = '2';
                        deque.push_back(make_pair(nRow, nCol));
                     }
                  }
               }
            }
         }
      }
      return result;
   }*/
    
public:
   int numIslands(vector<vector<char>> &grid) {
      int result = 0;
      queue<pair<int, int>> queue;
      for (size_t i = 0; i < grid.size(); i++) {
         for (size_t j = 0; j < grid[0].size(); j++) {
            if ('1' == grid[i][j]) {
               queue.push(make_pair(i, j));
               grid[i][j] = '2';  // Mark as visited
               ++result;
               while (false == queue.empty()) {
                  pair<int, int> coor = queue.front();
                  queue.pop();
                  int row = coor.first;
                  int col = coor.second;
                  static int dirs[] = {0, 1, 0, -1, 0};

                  for (int dirIndex = 0; dirIndex < 4; dirIndex++) {
                     int nRow = row + dirs[dirIndex];
                     int nCol = col + dirs[dirIndex + 1];

                     if (true == isValidCell(nRow, nCol, grid)) {
                        grid[nRow][nCol] = '2';
                        queue.push(make_pair(nRow, nCol));
                     }
                  }
               }
            }
         }
      }
      return result;
   }

   /*public:
       int numIslands(vector<vector<char>>& grid) {
           int result = 0;
           for(size_t i = 0; i < grid.size(); i++){
               for(size_t j = 0; j < grid[0].size(); j++){
                   if('1' == grid[i][j]){
                       DFT(i, j, grid);
                       ++result;
                   }
               }
           }
           return result;
       }
   private:
       void DFT(int row, int col, vector<vector<char>>& grid){
           grid[row][col] = '2';              	// Visited marker
           int dir[] = {0, 1, 0, -1, 0};

           for(int i = 0; i < 4; ++i){
               if(true == isValidCell(row + dir[i], col + dir[i + 1], grid)){
                   DFT(row + dir[i], col + dir[i + 1], grid);
               }
           }
       }*/

   bool isValidCell(int row, int col, vector<vector<char>> &grid) {
      if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || '1' != grid[row][col]) return false;
      return true;
   }
};