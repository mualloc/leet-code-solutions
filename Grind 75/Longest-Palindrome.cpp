class Solution {
public:
    int longestPalindrome(string s) {
        int freq[128] = {0};
        int oddCount = 0;
        
        for(auto & c :  s) {
            oddCount += ++freq[c - 'A'] & 1 ? 1 : -1;
        }
              
        return s.size() - oddCount + (oddCount > 0);
    }

    /*int longestPalindrome(string s) {
        if(s.size() < 2) return s.size();
        int charCount[Length::kAlphabetLength] = {0};
        int result = 0;
        
        for(const auto & c : s){
            int index = c - 'A';
            ++charCount[index];
            if(true == isEven(charCount[index])){
                result += 2;
            }
        }
        
        for(int i = 0; i < Length::kAlphabetLength; ++i){
            if(false == isEven(charCount[i])){ // Is odd?
                ++result;
                break;
            }
        }       
        return result;
    }
    
private:
    inline bool isEven(int number){
        return 0 == (number & 1);
    }
    
    enum Length{
        kAlphabetLength = 58,
    };*/
};