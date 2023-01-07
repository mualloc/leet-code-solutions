class Solution {
public:
    int calculate(string s) {
        int start = 0;
        return eval(s, start);
    }
 
private:
    int eval(const string & s, int & i){
        int result = 0;
        char sign = 1;
        int temp = 0;
        
        for( ; i < s.size() && ')' != s[i]; ++i){
            if(isDigit(s[i])){
                temp = 10 * temp + (s[i] - '0');
            }else{
                result += sign * temp;
                temp = 0;
                if('+' == s[i]) sign = 1;
                else if('-' == s[i]) sign = -1;
                else if('(' == s[i]) result += sign * eval(s, ++i); // Also, skips current '('
                // Else, skip spaces
            }            
        }
        return result + sign * temp;    
    }
    
    int isDigit(int c) {return c >= '0' && c <= '9';}
};

class Solution2 {
public:
    int calculate(string s) {
        vector<int> stack;
        int result = 0;
        char sign = 1;
        
        for(int i = 0; i < s.size(); i++){
            const char c = s[i];
            if(isDigit(c)){           // Digit
                int temp = c - '0';
                while(i + 1 < s.size() && isDigit(s[i + 1])){
                    ++i;
                    temp = 10 * temp + (s[i] - '0');
                }
                result += sign * temp;
            }else if('+' == c){ 
                sign = 1;
            }else if('-' == c){
                sign = -1;
            }
            else if('(' == c){
                stack.push_back(result);
                stack.push_back(sign);
                result = 0;
                sign = 1;
            }else if(')' == c){
                result *= stack.back(); stack.pop_back();   // Multiply with block sign
                result = result + stack.back(); stack.pop_back();   // Add sum before paranthesis
            }// Else, skip spaces          
        }
        return result;
    }
    
private:
    int isDigit(int c) {return c >= '0' && c <= '9';}
};


class Solution3 {
public:
    // https://medium.com/codex/funny-leetcode-hard-problem-basic-calculator-79e86c8fa26b
    int calculate(string s) {
        vector<char> signStack({1});
        int result = 0, temp = 0;
        char sign = 1;
        
        for(int i = 0; i < s.size(); i++){
            const char c = s[i];
            if(isDigit(c)){           // Digit
                temp = 10 * temp + (c - '0');
            }else if('+' == c || '-' == c){ 
                result += sign * temp;
                temp = 0;
                sign = ('+' == c ? 1 : -1) * signStack.back();              
            }else if('(' == c){
                signStack.push_back(sign);
            }else if(')' == c){
                signStack.pop_back();
            }
            // Else, skip spaces
        }
        
        result += sign * temp;
        return result;
	}
    
private:
    int isDigit(int c) {return c >= '0' && c <= '9';}
};