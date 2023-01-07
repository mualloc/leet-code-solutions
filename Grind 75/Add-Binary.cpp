class Solution {
public:
    string addBinary(string & a, string & b) {
        if(0 == a.size()) return b;
        if(0 == b.size()) return a;
        
        if('1' == a.back() && '1' == b.back()){
            a.pop_back(); b.pop_back();
            string one = "1";
            string remaining = addBinary(a, b);
            return addBinary(remaining, one) + '0';
        }else if('0' == a.back() && '0' == b.back()){
            a.pop_back(); b.pop_back();
            return addBinary(a, b) + '0';
        }else{
            a.pop_back(); b.pop_back();
            return addBinary(a, b) + '1'; 
        }
    }
    /*string addBinary(string a, string b) {
        string result;
        result.reserve(max(a.size(), b.size()) + 2);
        
        int carry = 0;     
        for(int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0 || 1 == carry; --i, --j){
            int aDigit = i >= 0 ? a[i] - '0' : 0;
            int bDigit = j >= 0 ? b[j] - '0' : 0;
            int total = aDigit + bDigit + carry;
            // char digit = '0' + (total & 1);
            char digit = '0' + aDigit ^ bDigit ^ carry;
            result += digit;
            carry = total >= 2;        
        }
        // return carry ? '1' + result : result;
        // return result;
        reverse(result.begin(), result.end());
        return result;
    }*/

    /*string addBinary(string a, string b) {
        string result;
        result.reserve(max(a.size(), b.size()) + 2);
        reverse(a.begin(), a.end()) , reverse(b.begin(), b.end());
        
        int carry = 0;     
        for(int i = 0; i < max(a.size(), b.size()); ++i){
            int aDigit =  i < a.size() ? a[i] - '0' : 0;
            int bDigit =  i < b.size() ? b[i] - '0' : 0;
            int total = aDigit + bDigit + carry;
            char digit = (total & 1) + '0';
            result = digit + result;
            carry = total >= 2;         
        }
        
        return carry ?  '1' + result : result;
    }*/
        
    /*string addBinary(string a, string b) {
        bool carry = false;
        string result;
        result.reserve(max(a.size(), b.size()) + 2);

        int i, j;
        for(i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--, j--){
            if(a[i] == b[j]){
                if('1' == a[i]){
                    if(true == carry) result = '1' + result;
                    else { result = '0' + result; carry = true; }
                }
                else{
                    if(true == carry) { result = '1' + result; carry = false; }
                    else result = '0' + result; 
                }
            }else{
                if(true == carry) result = '0' + result;
                else result = '1' + result;
            }
        }
        
        processRemaining(a, i, carry, result);
        processRemaining(b, j, carry, result);

        if(carry) result = '1' + result;
        return result;
    }
    
private:
    void processRemaining(string & remaining, int i, bool & carry, string & result){
        while(i >= 0){
            if('1' == remaining[i]){
                if(carry){
                    result = '0' + result;
                }else{ result = '1' + result;}
            }else{
                if(carry){
                    result = '1' + result;
                    carry = false;
                }else{ result = '0' + result;} 
            }
            --i;
        }        
    }*/
};