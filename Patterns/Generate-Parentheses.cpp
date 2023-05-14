// Catalan number: https://leetcode.com/problems/generate-parentheses/solutions/10127/an-iterative-method/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp;
        dp.push_back({""});

        for(int i = 1; i <= n; ++i){
            dp.push_back({});
            for(int j = 0; j < i; ++j){
                for(const auto& left : dp[j]){
                    for(const auto& right : dp[i - 1 - j]){
                        dp[i].push_back('(' + left + ')' + right);
                    }
                }
            }
        }
        return dp.back();
    }
};

class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        generateParenthesisHelper(n, n, curr, result);
        return result;
    }

private:
    void generateParenthesisHelper(int left_par_count, int right_par_count, string& curr, vector<string>& result) {
        if(0 == left_par_count && 0 == right_par_count) result.push_back(curr);
        curr += '(';
        if(left_par_count > 0) generateParenthesisHelper(left_par_count - 1, right_par_count, curr, result);
        curr.back() = ')';
        if(right_par_count > left_par_count) generateParenthesisHelper(left_par_count, right_par_count - 1, curr, result);
        curr.pop_back();
    }

    void generateParenthesisHelper2(int left_par_count, int right_par_count, string& curr, vector<string>& result) {
        if(0 == left_par_count && 0 == right_par_count) result.push_back(curr);
        else if(left_par_count > right_par_count) return;
        else if(-1 == left_par_count || -1 == right_par_count) return;
        else{
            curr += '(';
            generateParenthesisHelper2(left_par_count - 1, right_par_count, curr, result);
            curr.back() = ')';
            generateParenthesisHelper2(left_par_count, right_par_count - 1, curr, result);
            curr.pop_back();
        }
    }
};