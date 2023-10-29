// https://leetcode.com/problems/permutation-in-string/solutions/102590/8-lines-slide-window-solution-in-java/
class Solution {
public:
    // TC: O(S1 + S2)
    // SC: O(1)
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;

        array<int, 128> freqs{0};
        for(const auto& c : s1) --freqs[c];

        for(int left{0}, right{0}; right < s2.size(); ++right) {
            if(++freqs[s2[right]] > 0) while(0 != --freqs[s2[left++]]);
            else if(s1.size() == right - left + 1) return true;
        }
        return false;
    }
};


class Solution2 {
public:
    // TC: O(S1 + max(S2 - S1, 0))
    // SC: O(1)
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
		
        array<int, 26> s1_freqs{0};
        array<int, 26> s2_freqs{0};
        for(int i{0}, size = min(s1.size(), s2.size()); i < size; ++i) {
            ++s1_freqs[s1[i] - 'a'];
            ++s2_freqs[s2[i] - 'a'];
        }

        const auto target_count{26};
        auto count{0};
        for(int i{0}; i < s1_freqs.size(); ++i) count += s1_freqs[i] == s2_freqs[i];
        for(int i{0}; i < s2.size() - s1.size(); ++i) {
            if(target_count == count) return true;
			
            {
                const char left = s2[i] - 'a';
                --s2_freqs[left];
                if(s2_freqs[left] == s1_freqs[left]) ++count;
                else if(s2_freqs[left] + 1 == s1_freqs[left]) --count;
            }
            {
                const char right = s2[s1.size() + i] - 'a';
                ++s2_freqs[right];
                if(s2_freqs[right] == s1_freqs[right]) ++count;
                else if(s2_freqs[right] - 1 == s1_freqs[right]) --count;
            }
        }
        return target_count == count;
    }
};


class Solution3 {
public:
    // TC: O(S1 + S2)
    // SC: O(1)
    bool checkInclusion(string s1, string s2) {
        auto target_count{s1.size()};
        array<int, 26> freqs{0};
        for(const auto& c : s1) ++freqs[c - 'a'];
        auto left{0};
        for(const auto& c : s2) {
            const auto s2_c_index = c - 'a';
            --target_count;
            --freqs[s2_c_index];
            while(freqs[s2_c_index] < 0) {
                ++freqs[s2[left++] - 'a'];
                ++target_count;
            }
            if(0 == target_count) return true;
        }
        return false;
    }
};
