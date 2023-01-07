class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {        
        size_t rns = ransomNote.size();
        size_t ms = magazine.size();
        if(rns > ms){
            return false;
        }   
        int letterCount[26] = {0};
        
        for(size_t i = 0, j = 0; j < ms; i++, j++){
            if(i < rns){
                ++letterCount[ransomNote[i] - 'a'];
            }
             --letterCount[magazine[j] - 'a'];
        }
        for(size_t i = 0; i < 26; i++){
            if(letterCount[i] > 0){
                return false;
            }
        }
        return true;
    }
};