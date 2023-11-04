class Solution {
public:
    // TC: O(T)
    bool isSubsequence3(string s, string t) {
        auto i{0};
        for(auto j{0}; i < s.size() && j < t.size(); i += s[i] == t[j], ++j);
        return s.size() == i;
    }

    // TC: O(T)
    bool isSubsequence2(string s, string t) {
        if(0 == s.size()) return true;
        if(s.size() > t.size()) return false;
        for(auto i{0}, counter{0}; i < t.size(); ++i) if(t[i] == s[counter] && ++counter == s.size()) return true;
        return false;
    }

    // Follow Up: https://leetcode.com/problems/is-subsequence/solutions/87302/binary-search-solution-for-follow-up-with-detailed-comments/comments/172906
    // TC: O(T + k*S*logT)
    bool isSubsequence(string s, string t) {
        array<vector<int>, 128> indices;
        for(int i{0}; i < t.size(); ++i) indices[t[i]].push_back(i);

        int prev_index{-1};
        for(int i{0}; i < s.size(); ++i) {
            const auto& s_i{indices[s[i]]};
            if(auto it = upper_bound(s_i.begin(), s_i.end(), prev_index); it == s_i.end()) return false;
            else prev_index = *it;
        }
        return true;
    }
};
