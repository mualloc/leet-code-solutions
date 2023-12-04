class Solution {
public:
    // TC: O(m*n)
    // SC: O(m*n)
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> max_path_lens(m, vector<int>(n, 0));
        int result{0};
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(!max_path_lens[i][j]) dfs(i, j, matrix, max_path_lens);
                result = max(result, max_path_lens[i][j]);
            }
        }
        return result;
    }
private:
    void dfs(int row, int col, const vector<vector<int>>& matrix, vector<vector<int>>& max_path_lens) {
        if(max_path_lens[row][col]) return;
        static int dirs[5] = {1, 0, -1, 0, 1};
        for(int i = 0; i < 4; ++i) {
            const int nei_row{row + dirs[i]}, nei_col{col + dirs[i + 1]};
            if(nei_row < 0 || nei_row == m || nei_col < 0 || nei_col == n || matrix[nei_row][nei_col] <= matrix[row][col]) continue;
            dfs(nei_row, nei_col, matrix, max_path_lens);
            max_path_lens[row][col] = max(max_path_lens[row][col], max_path_lens[nei_row][nei_col]);
        }
        ++max_path_lens[row][col];
    }
    int m, n;
};
