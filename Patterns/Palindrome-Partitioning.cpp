class Solution {
public:
    // TC: O(N * (2 ^ N))
    // SC: O(N * (2 ^ N))
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        partitionHelper(s, 0, curr, result);
        return result;
    }

private:
    void partitionHelper(const string& s, int left, vector<string>& curr, vector<vector<string>>& result){
        if(left == s.size()){
            result.push_back(curr);
            return;
        }
        for(int right = left; right < s.size(); ++right){
            const string& prefix = s.substr(left, right - left + 1);
            if(isPalindrome(prefix)){
                curr.push_back(prefix);
                partitionHelper(s, right + 1, curr, result);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s) {
        for(int i = 0; i < s.size() / 2; ++i) {
            if(s[i] != s[s.size() - i - 1]) return false;
        }     
        return true; 
    }
};