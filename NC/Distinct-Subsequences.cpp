// https://leetcode.com/problems/distinct-subsequences/solutions/37316/7-10-lines-c-solutions-with-detailed-explanations-o-m-n-time-and-o-m-space/
class Solution {
// TC: O(s*t)
// SC: O(t)
public:
    int numDistinct(string s, string t) {
        vector<unsigned long> dp(t.size());         
        for(int j = 0; j < s.size(); ++j) {
            int up_left{1};
            for(int i = 0, up_left{1}; i < t.size(); ++i) {
                int temp = dp[i];
                dp[i] += (t[i] == s[j] ? up_left : 0);
                up_left = temp;
            }
        }
        return dp.back();
    }
};


// https://leetcode.com/problems/distinct-subsequences/solutions/37327/easy-to-understand-dp-in-java/
class Solution2 {
// TC: O(s*t)
// SC: O(s*t)
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned long>> dp(t.size() + 1, vector<unsigned long>(s.size() + 1));
        fill(dp.front().begin(), dp.front().end(), 1);

        for(int i = 0; i < t.size(); ++i) 
            for(int j = 0; j < s.size(); ++j) 
                dp[i + 1][j + 1] = dp[i + 1][j] + (t[i] == s[j] ? dp[i][j] : 0);
            
        return dp.back().back();
    }
};
