class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result{s};
        string curr;
        letterCasePermutationHelper(s, 0, result);
        return result;
    }

private:
    void letterCasePermutationHelper(string& s, int index, vector<string>& result) {
        if(index == s.size()) return;
        if(isalpha(s[index])) {
            s[index] = toggleCase(s[index]);
            result.push_back(s);
            letterCasePermutationHelper(s, index + 1, result);
            s[index] = toggleCase(s[index]);
        }
        letterCasePermutationHelper(s, index + 1, result);
    }

    char toggleCase(char c){
        if(isupper(c)) return tolower(c);
        else return toupper(c);
    }
};