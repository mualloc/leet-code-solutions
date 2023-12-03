class Solution {
public:
    // TC: O(n^2 * logn)
    // SC: O(n^2)
    int swimInWater(vector<vector<int>>& grid) {
        using depth_coor_t = pair<int, pair<int, int>>;
        priority_queue<depth_coor_t, vector<depth_coor_t>, greater<depth_coor_t>> heap;
        heap.push(make_pair(grid[0][0], make_pair(0, 0)));
        grid[0][0] = -1;
        int dirs[5] = {1, 0, -1, 0, 1};
        const int len = grid.size();
        while(true) {
            auto [depth, coors] = heap.top(); heap.pop();
            const auto& [row, col] = coors;
            if(row == len - 1 && col == len - 1) return depth;
            for(int i = 0; i < 4; ++i) {
                int nei_row{row + dirs[i]}, nei_col{col + dirs[i + 1]};
                if(IsAvailableCell(nei_row, nei_col, grid)) {
                    heap.push(make_pair(max(grid[nei_row][nei_col], depth), make_pair(nei_row, nei_col)));
                    grid[nei_row][nei_col] = -1;
                }
            }
        }
    }
private:
    bool IsAvailableCell(int row, int col, const vector<vector<int>>& grid) {
        return row >= 0 && row < grid.size() && col >= 0 && col < grid.size() && -1 != grid[row][col];
    }
};
