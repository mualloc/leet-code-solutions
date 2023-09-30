// https://leetcode.com/problems/substring-with-concatenation-of-all-words/solutions/1753357/clear-solution-easy-to-understand-with-diagrams-o-n-x-w-approach/
class Solution {
public:
    // TC: O(N * WS)
    // SC: O(WS * WC)
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        unordered_map<string, int> target_words;
        for(const auto& word : words) ++target_words[word];
        const auto word_size = words[0].size();
        const auto target_word_count = words.size();
        for(int i = 0; i < word_size; ++i) { // O(WS)
            int left = i;
            int count = 0;
            unordered_map<string, int> found_words;
            for(int j = i; j + word_size <= s.size(); j += word_size){  // O(N/WS)
                const auto curr_word = s.substr(j, word_size);  // O(WS)
				const auto targeted_curr_word_count = target_words[curr_word];
                if(0 == targeted_curr_word_count) {
                    found_words.clear();
                    count = 0;
                    left = j + word_size;
                }else{
                    ++found_words[curr_word];
                    ++count;
                    auto& curr_word_count = found_words[curr_word];
                    while(curr_word_count > targeted_curr_word_count){
                        string discard_word = s.substr(left, word_size);
                        --found_words[discard_word];
                        --count;
                        left += word_size;
                    }
                    if(target_word_count == count) result.push_back(left);
                }
            }
        }
        return result;
    }
};
