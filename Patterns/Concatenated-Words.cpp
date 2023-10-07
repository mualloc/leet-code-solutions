// https://leetcode.com/problems/concatenated-words/solutions/3103555/c-simple-dp-with-full-explanation-beats-99/
class Solution {
public:
    // TC: O(W * L^3)
    // SC: O(W * L)
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dictionary{words.begin(), words.end()};

        vector<string> result;
        for(const auto& word : words){
            const int word_size = word.size();
            vector<int> dp(word_size + 1, false);
            dp[0] = true;
            for(int start = 0; start < word_size; ++start){
                if(false == dp[start]) continue;
                for(int end = start; end < word_size; ++end){
                    const int length = end - start + 1;
                    if(word_size != length){   // Avoid the exact word!
                        if(dictionary.end() != dictionary.find(move(word.substr(start, length)))) dp[end + 1] = true;
                    }
                }
                if(true == dp.back()) {
                    result.push_back(word);
                    break;
                }
            }
        }
        return result;
    }
};


class Solution2 {
public:
    // TC: O(W * L^3)
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dictionary{words.begin(), words.end()};
        vector<string> result;
        unordered_map<string, bool> cache;
        for(const auto& word : words){
            dictionary.erase(word);
            if(true == isConcatenated(word, dictionary, cache)) result.push_back(word);
            dictionary.insert(word);
        }
        return result;
    }
private:
    bool isConcatenated(const string& word, const unordered_set<string>& dictionary, unordered_map<string, bool>& cache) {
        if(auto it = cache.find(word); cache.end() != it) return it->second;
        
        string sub_str;
        sub_str.reserve(word.size());
        for(int sub_str_size = 1; sub_str_size <= word.size(); ++sub_str_size){
            sub_str += word[sub_str_size - 1];
            if(dictionary.end() != dictionary.find(sub_str)) {
                string suffix = word.substr(sub_str_size);
                if(dictionary.end() != dictionary.find(suffix) || isConcatenated(suffix, dictionary, cache)) return cache[word] = true;
            }
        }        
        return cache[word] = false;
    }
};
