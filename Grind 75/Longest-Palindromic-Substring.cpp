class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0, pos = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        
        for(int start = s.size() - 1; start >= 0; start--){
            for(int end = start; end < s.size(); end++){
                if(s[start] == s[end]){
                    if(end - start < 3 || dp[start + 1][end - 1]){
                        dp[start][end] = true;
                        if(end - start + 1 > maxLen) {
                            maxLen = end - start + 1;
                            pos = start;
                        }
                    }
                }
            }
        }
        return s.substr(pos, maxLen);
    }
};


class Solution2 {
public:
    string longestPalindrome(string s) {
        for(int i = 0; i < s.size() - (end - start) / 2; i++){
            extend(s,i,i);      // odd length, like "aba"
            extend(s,i,i + 1);  // even length, like "abba"
        }
        return s.substr(start, end - start + 1);
    }
    
private:
    void extend(const string & s, int left, int right){
        while(left >= 0 && right <= s.size() - 1 && s[left] == s[right]){
                --left; ++right;
            }
        left++; right--;    // Return back to last valid positions
        if(right - left  > end - start) { start = left; end = right; }       
    }
    
    int start = 0, end = 0;
};


class Solution3 {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                int k = 0;
                while(k + i <= j - k && s[i + k] == s[j - k]) k++;
                if(k + i > j - k){      // Check if palindrome
                    if(j - i > end - start) { start = i; end = j; }
                }                                 
            }
        }
        return s.substr(start, end - start + 1);
    }
};