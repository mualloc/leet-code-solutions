class Solution {
public:
    int myAtoi(string s) { 
        int sign = 1;
        int i = 0;
        while(i < s.size() && ' ' == s[i]) i++;   // Skip leading whitespace
        if(i < s.size() && ('+' == s[i] || '-' == s[i])) sign = '-' == s[i++] ? -1 : 1;
        
        int result = 0;
        while(i < s.size() && isdigit(s[i])){
            int digit = s[i++] - '0';
            if(result > (INT_MAX - digit) / 10) return 1 == sign ? INT_MAX : INT_MIN;     
            /*if(1 == sign){
                // [0, 2,147,483,647]
                if(result > (INT_MAX - digit) / 10) 
                if(result > kINT_MAX_BASE || (kINT_MAX_BASE == result && s[i] - '0' >= kINT_MAX_LAST_DIGIT)) return INT_MAX;
            }else{
                // [-2,147,483,648, 0]
                if(result > kINT_MAX_BASE || (kINT_MAX_BASE == result && s[i] - '0' > kINT_MAX_LAST_DIGIT)) return INT_MIN;  
            }*/
            result = result * 10 + digit;                
        }     
        return sign * result;
    }
private:
    enum Constants{
        kINT_MAX_BASE = INT_MAX / 10,
        kINT_MAX_LAST_DIGIT = INT_MAX % 10,
    };
};