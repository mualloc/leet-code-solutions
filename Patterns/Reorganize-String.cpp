class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    string reorganizeString(string s) {
        array<int, 128> freqs{0};
        int maxFreq = INT_MIN;
        char maxChar = 0;
        for(const char& c : s) {
            if(++freqs[c] > maxFreq) {
                maxFreq = freqs[c];
                maxChar = c;
            }
        }
        const int ssize = s.size();
        if(maxFreq > (ssize + 1) / 2) return "";
        string reorganized(ssize, 0);
        int index = 0;
        while(freqs[maxChar]-- > 0){
            reorganized[index] = maxChar;
            index += 2;
        }
        for(int i = 0; i < freqs.size(); ++i){
            while(freqs[i]-- > 0){
                if(index >= ssize) index = 1;
                reorganized[index] = i;
                index += 2;
            }
        }
        return reorganized;
    }
};


class Solution2 {
public:
    // TC: O(N * log(26))
    // SC: O(1)
    string reorganizeString(string s) {
        array<int, 26> freqs{0};
        for(const char& c : s) ++freqs[c - 'a'];
        priority_queue<pair<int, int>> freqCharMaxHeap;
        for(int i = 0; i < freqs.size(); ++i){
            if(freqs[i] > 0) freqCharMaxHeap.emplace(freqs[i], i + 'a');
        }

        auto prev = make_pair(0, 0);
        auto reorganized = s;
        for(int index = 0; false == freqCharMaxHeap.empty(); ++index){
            auto[freq, character] = freqCharMaxHeap.top(); freqCharMaxHeap.pop();
            reorganized[index] = character;
            if(prev.first) freqCharMaxHeap.push(prev);
            prev = make_pair(--freq, character);
        }
        return 0 != prev.first ? "" : reorganized;
    }
};
