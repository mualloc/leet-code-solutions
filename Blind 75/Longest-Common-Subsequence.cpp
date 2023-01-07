class Solution {
public:
    // TC: O(M * N)
    // SC: O((M,N))
    int longestCommonSubsequence(string text1, string text2) {
        const int sText1 = text1.size();
        const int sText2 = text2.size();
        vector<int> dp(sText2 + 1, 0);
        
        for(int i = 0; i < sText1; ++i){
            int upDiagonal = 0;     // ie. dp[i][j]
            for(int j = 0; j < sText2; ++j){
                int temp = dp[j + 1];  // Holds up-diagonal value for the next iteration
                if(text1[i] == text2[j]) dp[j + 1] = upDiagonal + 1; 
                else dp[j + 1] = max(dp[j], dp[j + 1]);
                upDiagonal = temp;
            }
        }
        
        return dp.back();
    }
    
    // TC: O(M * N)
    // SC: O(2 * N)
    int longestCommonSubsequence2(string text1, string text2) {
        const int sText1 = text1.size();
        const int sText2 = text2.size();
        vector<vector<int>> dp(2, vector<int>(sText2 + 1, 0));
        
        unsigned char currRow = 0, upRow = 1;
        for(int i = 0; i < sText1; ++i, upRow ^= 1, currRow ^= 1){
            for(int j = 0; j < sText2; ++j){
                if(text1[i] == text2[j]) dp[currRow][j + 1] = dp[upRow][j] + 1; 
                else dp[currRow][j + 1] = max(dp[currRow][j], dp[upRow][j + 1]);    
            }
        }
        
        return dp[(sText1 + 1) % 2].back();
    }
    
    
    // TC: O(M * N)
    // SC: O(M * N)
    int longestCommonSubsequence3(string text1, string text2) {
        const int sText1 = text1.size();
        const int sText2 = text2.size();
        vector<vector<int>> dp(sText1 + 1, vector<int>(sText2 + 1, 0));
        
        for(int i = 0; i < sText1; ++i){
            for(int j = 0; j < sText2; ++j){
                if(text1[i] == text2[j]) dp[i + 1][j + 1] = dp[i][j] + 1; 
                else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);    
            }
        }
        
        return dp.back().back();
    }
};