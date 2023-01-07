class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(0 == digits.size()) return {};
        const vector<string> map {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
        
        vector<string> result({""});
        for(const auto & digit : digits){
            vector<string> temp;
            for(const string & curr : result){
                for(const char & c : map[digit - '0']){
                    temp.push_back(curr + c);
                }
            }
            result.swap(temp);
        }
        
        return result;
    }
};


class Solution2 {
public:
    Solution2(){
        unsigned char c = 'a';
        for(int num = '2'; num <= '9'; ++num, ++c){
            if('7' == num || '9' == num) map[num] = {c, ++c, ++c, ++c}; 
            else map[num] = {c, ++c, ++c}; 
        }
    }
    
    // TC: O(N * 4^N)
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(0 == digits.size()) return result;
        
        string curr(digits.size(), 0);
        letterCombinationsHelper(digits, 0, curr, result);
          
        return result;
    }

private:
    void letterCombinationsHelper(const string & digits, int i, string & curr, vector<string> & result){
        if(i == digits.size()){
            result.push_back(curr);
        }else{
            for(const char & c : map[digits[i]]){
                curr[i] = c;
                letterCombinationsHelper(digits, i + 1, curr, result);
            }
        }
    }
    
    unordered_map<unsigned char, vector<unsigned char>> map;
};