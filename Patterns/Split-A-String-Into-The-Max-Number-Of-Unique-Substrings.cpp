class Solution {
public:
    // TC: O(N * 2^N)
    // SC: O(N)
    int maxUniqueSplit(string s) {
        unordered_set<string> substrings;
        int result{0};
        backtrack(s, 0, substrings, result);
        return result;
    }
private:
    void backtrack(const string& s, const int left, unordered_set<string>& substrings, int& result) {
        if(s.size() == left) result = max(result, static_cast<int>(substrings.size()));
                    
        for(int right = left, s_size = s.size(); right < s_size; ++right) {
            const auto substr{s.substr(left, right - left + 1)};    // <-- Multiplication by N in TC comes from this substr()!
            if(true == substrings.insert(substr).second) {
                backtrack(s, right + 1, substrings, result);
                substrings.erase(substr);
            }
        }
    }
};
