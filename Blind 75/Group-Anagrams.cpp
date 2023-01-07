class Solution {
public:
    // TC:O(m * n * (26 + 26)) --> fill() + hash_map() cost
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string freq(26, 0);
        unordered_map<string, vector<string>> anagrams;
        
        for(const string & str : strs){
            std::fill(freq.begin(), freq.end(), 0);
            for(const auto & c : str) ++freq[c - 'a'];
            anagrams[freq].emplace_back(move(str));
        }
       
        vector<vector<string>> result; 
        result.reserve(anagrams.size());
        for(const auto & anagram : anagrams) {
            result.emplace_back(move(anagram.second));  
        }
        return result;
    }
};

class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        
        for(const auto & str : strs){
            /*string temp{str};
            sort(temp.begin(), temp.end());
            anagrams[move(temp)].push_back(move(str));*/
            anagrams[move(bucketSort(str))].push_back(move(str));
        }
        
        vector<vector<string>> result; 
        result.reserve(anagrams.size());
        for(const auto & anagram : anagrams) {
            result.emplace_back(move(anagram.second));  
        }
        return result;
    }
        
private:
    string bucketSort(const string & str){
        unsigned char freq[26] = {0};
        for(const auto & c : str) ++freq[c - 'a'];
            
        string result;
        for(int i = 0; i < sizeof(freq) / sizeof(freq[0]); ++i){
            if(0 != freq[i]) result += string(freq[i], 'a' + i);
        }
        return result;
    }
};