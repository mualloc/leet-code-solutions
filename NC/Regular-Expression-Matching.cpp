// https://leetcode.com/problems/regular-expression-matching/solutions/191830/java-dp-solution-beats-100-with-explanation/
class Solution {
    // TC: O(p*s)
    // SC: O(p*s)
    // Bottom-up
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for(int j{1}; j < p.size(); j += 2) dp[0][j + 1] = '*' == p[j] && dp[0][j - 1];

        for(int i{0}; i < s.size(); ++i) {
            for(int j{0}; j < p.size(); ++j) {
                if('*' == p[j]) dp[i + 1][j + 1] = dp[i + 1][j - 1] || (dp[i][j + 1] && (s[i] == p[j - 1] || '.' == p[j - 1]));
                else if(s[i] == p[j] || '.' == p[j])  dp[i + 1][j + 1] = dp[i][j];
            }
        }
        return dp.back().back();
    }
};


// https://leetcode.com/problems/regular-expression-matching/solutions/883719/python-top-down-dp-clean-concise-o-m-n/
class Solution2 {
    // TC: O(p*s)
    // SC: O(p*s)
    // Top-down
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return checkMatch(0,s,0,p,dp);
    }
private:
    int checkMatch(int i, const string& s, int j, const string& p, vector<vector<int>>& dp) {
        if(-1 != dp[i][j]) return dp[i][j];
        if(j == p.size()) return dp[i][j] = i == s.size();

        const auto is_char_matched{i < s.size() && (s[i] == p[j] || ('.' == p[j]))};
        if(j + 1 < p.size() && '*' == p[j + 1]) return dp[i][j] = checkMatch(i, s, j + 2, p, dp) || (is_char_matched && checkMatch(i + 1, s, j, p, dp));
        return dp[i][j] = is_char_matched && checkMatch(i + 1, s, j + 1, p, dp);
    }
};
