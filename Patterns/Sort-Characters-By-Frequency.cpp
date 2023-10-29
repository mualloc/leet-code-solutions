class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    string frequencySort(string s) {
        array<int, 128> freqs{0};
        for(const auto& c : s) ++freqs[c];
        priority_queue<pair<int, char>> freq_char_heap;
        for(auto i{0}; i < freqs.size(); ++i) if(freqs[i]) freq_char_heap.emplace(freqs[i], i);
        
        string sorted;
        sorted.reserve(s.size());
        while(false == freq_char_heap.empty()){
            auto [freq, character] = freq_char_heap.top();
            freq_char_heap.pop();
            sorted += string(freq, character);
        }
        return sorted;
    }
};


class Solution2 {
public:
    // TC: O(N)
    // SC: O(N)
    string frequencySort(string s) {
        array<int, 128> freqs{0};
        for(const auto& c : s) ++freqs[c];
        vector<string> buckets(s.size() + 1);
        for(int i = 0; i < freqs.size(); ++i) if(freqs[i]) buckets[freqs[i]] += i;

        string sorted;
        sorted.reserve(s.size());
        for(auto i{buckets.size() - 1}; i > 0; --i) 
            for(const auto& c : buckets[i]) sorted += string(i, c);
        
        return sorted;
    }
};


// https://leetcode.com/problems/sort-characters-by-frequency/solutions/1503201/c-python-3-solutions-sorting-bucket-sort-o-n-clean-concise/
class Solution3 {
public:
    // TC: O(N * logN)
    // SC: O(N)
    string frequencySort(string s) {
        array<int, 128> freqs{0};
        for(const auto& c : s) ++freqs[c];
        sort(s.begin(), s.end(), [&freqs](char c1, char c2) {return freqs[c1] > freqs[c2] || (freqs[c1] == freqs[c2] && c1 < c2);});
        return s;
    }
};
