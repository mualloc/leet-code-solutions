class Solution {
public:
    bool isValid(string s) {
        stack<char> characterStack;
        for(const char & c : s){
            switch (c){
                case '(':
                case '{':
                case '[':
                    characterStack.push(c);
                    break;
                case ')':
                case '}':
                case ']':
                {
                    if(true == characterStack.empty()){
                        return false;
                    }
                    char counterChar = CounterCharacter(c);
                    char prevChar = characterStack.top();
                    characterStack.pop();
                    if(prevChar != counterChar)
                    {
                        return false;
                    }
                    break;
                }
            }
        }
        return characterStack.empty();
    }
    
    private:
    char CounterCharacter(char c){
        switch (c){
            case ')':
                return '(';
            case '}':
                return '{';
            case ']':
                return '[';
            default:
                return 0;
        }
    }
};