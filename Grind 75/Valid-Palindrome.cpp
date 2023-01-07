class Solution {
public:
    bool isPalindrome(string s) {
        size_t startIndex = 0;
        size_t endIndex = s.size() - 1;
        
        while(startIndex < endIndex)
        {
            if(0 == isalnum(s[startIndex])){
                ++startIndex;
            }else if(0 == isalnum(s[endIndex])){
                --endIndex;
            }else{
                if(tolower(s[startIndex++]) != tolower(s[endIndex--])){
                    return false;
                }
            }
        }
        return true;
    }
};