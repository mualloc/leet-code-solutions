class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // https://www.youtube.com/watch?v=wiGpQwVHdE0
        /*unordered_set<char> set;
        // Holds starting index of last substring
        int left = 0;
        size_t sSize = s.size();
        int result = 0;
        
        for(int right = 0; right < sSize; right++){
            char c = s[right];
            while(set.end() != set.find(c)){
                set.erase(s[left]);
                left++;
            }
            set.insert(c);
            result = std::max(result , right - left + 1);
        }
        return result;*/
        
        std::unordered_map<char, int> map;
        size_t sSize = s.size();
        size_t startingIndexOfLastString = 0;
        size_t maxLength = 0;
        
        for(size_t i = 0; i < sSize; i++){
            const char& c = s[i];
            if(map.end() != map.find(c)){
                int index = map[c];
                if(index >= startingIndexOfLastString){
                    maxLength = std::max(maxLength, i - startingIndexOfLastString - 1 + 1);
                    startingIndexOfLastString = map[c] + 1;
                }
            }
            map[c] = i;
        }
        return std::max(maxLength, sSize - startingIndexOfLastString);
    }
};