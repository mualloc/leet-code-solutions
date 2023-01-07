// NOTE: BUNU ANLA!!!!!
class Solution {
public:
    // TC: O(N)
    int characterReplacement(string s, int k) {
        vector<int> freqs(26);        
        int maxFreq = 0;
        int result = 0;
        
        for(int left = 0, right = 0; right < s.size(); ++right){
            maxFreq = max(maxFreq, ++freqs[s[right] - 'A']);
            if(right - left + 1 - maxFreq > k) --freqs[s[left++] - 'A'];
            else result = max(result, right - left + 1);
        }
        return result;
    }
};


class Solution2 {
public:
    // TC: O(N * 26)
    int characterReplacement(string s, int k) {
        vector<int> freqs(26);        
        int result = 0;
        for(int left = 0, right = 0; right < s.size(); ++right){
            ++freqs[s[right] - 'A'];
            const int seqLen = right - left + 1;
            if(seqLen - *max_element(freqs.begin(), freqs.end()) > k) --freqs[s[left++] - 'A'];
            else result = max(result, seqLen);
        }
        return result;
    }
};