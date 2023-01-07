class Solution {
public:
    int uniquePaths2(int m, int n) {
        vector<int> currRow(n, 1);
             
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                currRow[j] += currRow[j - 1];
            }
        }
        return currRow.back();
    }
    /////////////////////////////////////////////////////////////////////////////
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(2, vector<int>(n, 1));
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i & 1][j] = dp[i & 1][j - 1] +  dp[(i - 1) & 1][j];  // Note '&' for toggling between dp rows!
            }
        }
        return dp[(m - 1) & 1].back();
        
        /*vector<int> prevRow(n, 1);
        vector<int> currRow(n);
        currRow[0] = 1;
             
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                currRow[j] = currRow[j - 1] +  prevRow[j];
            }
            swap(prevRow, currRow);
        }
        return prevRow.back();  // currRow fails for the input (1,2)*/
    }
    /////////////////////////////////////////////////////////////////////////////
    int uniquePaths3(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; i++) dp[i][0] = 1;
        for(int j = 0; j < n; j++) dp[0][j] = 1;
             
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i][j - 1] +  dp[i - 1][j];
            }
        }
        return dp.back().back();
    }    
};


class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        dp.back().back() = 1;
        return uniquePathsHelper(0, 0, dp);
    }
    
private:
    int uniquePathsHelper(int m, int n, vector<vector<int>> & dp) {
        if(m == dp.size() || n == dp[0].size()) return 0;
        // if(m == dp.size() - 1 && n == dp[0].size() - 1) return 1;
        if(dp[m][n]) return dp[m][n];
        
        return dp[m][n] = uniquePathsHelper(m + 1, n, dp) + uniquePathsHelper(m, n + 1, dp);
    }
};


class Solution3 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;
        return uniquePathsHelper(m - 1, n - 1, dp);
    }

private:
    int uniquePathsHelper(int m, int n, vector<vector<int>> & dp) {
        if(-1 == m || -1 == n) return 0;
        if(-1 != dp[m][n]) return dp[m][n];         
        return dp[m][n] = uniquePathsHelper(m - 1, n, dp) + uniquePathsHelper(m, n - 1, dp);
    }
};


class Solution4 {
public:
    // https://betterexplained.com/articles/navigate-a-grid-using-combinations-and-permutations/
    // TC: O(min(m,n))
    int uniquePaths(int m, int n) {
        int abv = m + n - 1 - 1;
        int blw = min(m - 1, n - 1);
        long result = 1;
        
        for(int i = 1; i <= blw; ++i){
            result *= abv--;
            result /= i;
        }
        return result;
    }
};