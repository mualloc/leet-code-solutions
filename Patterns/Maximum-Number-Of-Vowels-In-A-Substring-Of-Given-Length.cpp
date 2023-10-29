class Solution {
public:
    int maxVowels(string s, int k) {
        auto result{0};
        auto left{0};
        auto curr_count{0};
        for(int i{0}, s_size = s.size(); i < s_size; ++i) {
            curr_count += isVowel(s[i]);
            if(i >= k) curr_count -= isVowel(s[i-k]);
            result = max(result, curr_count);
        }
        return result;
    }
private:
    bool isVowel(char c) { return 'a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c; }
};
