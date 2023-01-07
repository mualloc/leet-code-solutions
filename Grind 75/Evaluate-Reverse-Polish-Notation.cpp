// NOTE: O(1) Space çözümü incele!
//https://leetcode.com/problems/evaluate-reverse-polish-notation/discuss/1229370/Short-and-Simple-Solution-w-Explanation-or-O(N)-and-O(1)-Space-Solutions

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size() - 1;
        return solve(tokens, n);
    }
    
    long int solve(vector<string>& tokens, int & i){
        const string & token = tokens[i];
        if("+" == token || "-" == token || "*" == token || "/" == token){
            char oprator = token[0];
            int opRight = solve(tokens, --i);
            int opLeft = solve(tokens, --i);
            if('+' == oprator) return opLeft + opRight;
            else if('-' == oprator) return opLeft - opRight;
            else if('/' == oprator) return opLeft / opRight;
            else return opLeft * opRight;         
        }
        return stoi(token);
    }
    
    /*int evalRPN(vector<string>& tokens) {
        stack<int> operandStack;
        
        for(const auto & token : tokens){
            OperatorType ot = operatorType(token);
            if(kUndefined == ot){   // Token is an operand ie.number
                operandStack.push(stoi(token));
            }else{      // Token is an operator
                int opRight = operandStack.top(); operandStack.pop();
                int opLeft = operandStack.top(); operandStack.pop();
                int operationResult = performOperation(ot, opLeft, opRight);
                operandStack.push(operationResult);
            }
        }
        return operandStack.top();
    }
    
private:
        enum OperatorType{
            kUndefined,
            kAddition,
            kSubtraction,
            kDivision,
            kMultiplication
        };
    
        int performOperation(OperatorType ot, int opLeft, int opRight){
            switch(ot){
                case OperatorType::kAddition:
                        return opLeft + opRight;
                case OperatorType::kSubtraction:
                        return opLeft - opRight;
                case OperatorType::kDivision:
                        return opLeft / opRight;
                case OperatorType::kMultiplication:
                        return opLeft * opRight;                   
            }
            return INT_MIN;     // Error case
        }
    
        OperatorType operatorType(string token){
            if("+" == token) return OperatorType::kAddition;          
            else if("-" == token) return OperatorType::kSubtraction;
            else if("/" == token) return OperatorType::kDivision;
            else if("*" == token) return OperatorType::kMultiplication;
            else return OperatorType::kUndefined;
        }*/
};