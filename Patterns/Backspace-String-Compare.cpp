class Solution {
public:
    // TC: O(S + T)
    // SC: O(1)
    bool backspaceCompare(string s, string t) {
        const auto apply_backspace = [](const auto& s, auto& index) { for(int backspace_count{0}; index >= 0 && (backspace_count > 0 || '#' == s[index]); backspace_count += '#' == s[index--] ? 1 : -1); };
        for(int s_right =  s.size() - 1, t_right = t.size() - 1; s_right >= 0 || t_right >= 0; --s_right, --t_right) {
            apply_backspace(s, s_right);
            apply_backspace(t, t_right);
            if(s_right < 0 && t_right < 0) return true;
            if((s_right < 0) ^ (t_right < 0)) return false;
            if(s[s_right] != t[t_right]) return false;
        }
        return true;
    }
};


// https://leetcode.com/problems/backspace-string-compare/solutions/570511/c-simple-and-easy-explanation-100-memory-and-100-speed-0ms-o-1-space-o-n-time/comments/1171107
class Solution2 {
public:
    // TC: O(S + T)
    // SC: O(1)
    bool backspaceCompare(string s, string t) {
        const auto apply_backspace = []
                (auto& s) {
                    auto last_valid_index{-1};
                    for(int i{0}; i < s.size(); ++i) 
                        if('#' == s[i]) last_valid_index = max(--last_valid_index, -1);
                        else s[++last_valid_index] = s[i];
                    return last_valid_index + 1;
                };  
        auto s_len{apply_backspace(s)};
        auto t_len{apply_backspace(t)};
        return s_len == t_len && 0 == strncmp(s.c_str(), t.c_str(), s_len);
    }
};
