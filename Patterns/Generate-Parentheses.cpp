class Solution {
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