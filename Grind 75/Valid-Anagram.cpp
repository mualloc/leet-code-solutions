class Solution {
public:
    bool isAnagram(string s, string t) {
        size_t sLength = s.size();
        size_t tLength = t.size();
        if(sLength != tLength){
            return false;
        }
        size_t characterCount[26] = {0};
        
        for(size_t i = 0; i < sLength; i++){
            size_t sIndex = s[i] - 'a';
            size_t tIndex = t[i] - 'a';
            ++characterCount[sIndex];
            --characterCount[tIndex];       
        }
        
        for(size_t i = 0; i < 26; i++){
            if(0 != characterCount[i]){
                return false;
            }
        }
        return true;
    }
};