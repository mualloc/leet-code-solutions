class Solution {
public:
    int numDecodings(string s) {
        if('0' == s[0]) return 0;
        
        const int sSize = s.size();        
        int first = 0, second = 0;
        if(isValidNumber(s, sSize - 1, sSize - 1)) first = 1;
        for(int i = sSize - 2; i >= 0; --i){
            int temp = 0;
            if(isValidNumber(s, i, i)) {
                temp += first;
                if(i + 1 < sSize && isValidNumber(s, i, i + 1)) {
                    if(i + 2 < sSize) temp += second;
                    else temp += 1;
                }
            }
            second = first;
            first = temp;
        } 
    
        return first;
    }
    
private:
    bool isValidNumber(const string & word, int start, int end){
        if('0' == word[start]) return false;
        else if(end == start + 1){
            if(word[start] > '2' || '2' == word[start] && word[end] > '6') return false;
        }
        return true;
    }
};