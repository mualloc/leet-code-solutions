class Solution {
public:

    // NOTE: Very good explanation: https://leetcode.com/problems/flood-fill/discuss/473494/Java-DFS-BFS-Solutions-Space-complexity-Analysis-Clean-and-Concise
    /*vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]){
            return image;
        }
        fill(image, sr, sc, image[sr][sc], color);
        return image;
    }
    
private:
    void fill(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || oldColor != image[sr][sc]){
            return;
        }
        image[sr][sc] = newColor;
        fill(image, sr - 1, sc, oldColor, newColor);
        fill(image, sr + 1, sc, oldColor, newColor);
        fill(image, sr, sc - 1, oldColor, newColor);
        fill(image, sr, sc + 1, oldColor, newColor); 
    }*/
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]){
            return image;
        }
        
        queue<std::pair<int,int>> queue;
        int originalColor = image[sr][sc];       
        image[sr][sc] = color;
        queue.push(make_pair(sr,sc));
        int dr[] = {0,  0, 1, -1}; // down, up
        int dc[] = {1, -1, 0,  0}; // right, left
        
        while(false == queue.empty()){
            pair<int, int> coor = queue.front();
            queue.pop();
            
            for(size_t i = 0; i < sizeof(dr) / sizeof(dr[0]); i++){
                int row = coor.first + dr[i];
                int col = coor.second + dc[i];
                if(true == Valid(image, row, col, originalColor, color)){
                    image[row][col] = color;
                    queue.push(make_pair(row, col));
                }
            }
        }
        return image;
    }
    
    private:
    // Check position, color and visit state
    bool Valid(vector<vector<int>>& image, int row, int col, int expansionColor, int newColor){
        size_t rowCount = image.size();
        size_t colCount = image[0].size();
        if(row >= rowCount || row < 0 || col >= colCount || col < 0 || expansionColor != image[row][col] /*|| newColor == image[row][col]*/){
            return false;
        }
        return true;
    }
};