class Solution {
public:
    // TC: O(N^2)
    int countSubstrings(string s) {
        int result = 0;
        for(int i = 0, sSize = s.size(); i < sSize; ++i) { 
            result += extend(s, i, i) + extend(s, i, i + 1); 
        }
        return result;
    }
 
private:
    int extend(const string & s, int left, int right){
        int result = 0;
        const int sSize = s.size();
        while(left >= 0 && right < sSize && s[left--] == s[right++]) ++result;
        return result;
    }
};


class Solution2 {
public:
    // TC: O(N^2)
    // SC: O(N^2)
    // Bottom-Up DP
    int countSubstrings(string s) {
        int result = 0;
        int const sSize = s.size();
        vector<vector<bool>> dp(sSize, vector<bool>(sSize, false));
        
        for(int start = sSize - 1; start >= 0; --start){
            for(int end = start; end < sSize; ++end){
                if(s[start] == s[end] && (end - start < 3 || dp[start + 1][end - 1])){
                    dp[start][end] = true;
                    result++;
                }
            }
        }
        return result;
    }
};