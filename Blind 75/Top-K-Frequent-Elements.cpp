class Solution {
public:
    // TC: O(N)
    // SC: O(N)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num2Freqs;
        int maxFreq = INT_MIN;
        for(const int & num : nums) maxFreq = max(maxFreq, ++num2Freqs[num]);
        
        vector<vector<int>> buckets(maxFreq + 1);
        for(const auto & num2Freq : num2Freqs)  buckets[num2Freq.second].push_back(num2Freq.first);
               
        vector<int> result; result.reserve(k);
        for(int i = buckets.size() - 1; i >= 0 && result.size() < k; --i){
            result.insert(result.end(), buckets[i].begin(), buckets[i].end());
        }
            
        return result;
    }
};

class Solution2 {
public:
    // TC: O(k * logN)
    // SC: O(N)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num2Freqs;
        for(const int & num : nums) ++num2Freqs[num];
        vector<pi> freqs;   freqs.reserve(num2Freqs.size());
        for(const auto & [num, freq] : num2Freqs) freqs.emplace_back(freq, num);
        make_heap(freqs.begin(),freqs.end());   // Max heap
        
        vector<int> result; result.reserve(k);
        while(k--){
            result.push_back(freqs.front().second);
            pop_heap(freqs.begin(), freqs.end());   freqs.pop_back();
        }
        return result;
    }
    
private:
    typedef pair<int, int> pi;
};


class Solution3 {
public:
    // TC: O(N * logk)
    // SC: O(N)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for(const int & num : nums) ++freqs[num];

        std::priority_queue<pi, std::vector<pi>, std::greater<pi>> pq;    // Min heap
        for(const auto & freq : freqs){
            if(pq.size() < k || freq.second > pq.top().first) pq.push(make_pair(freq.second, freq.first));
            if(pq.size() > k) pq.pop();    
        }
        
        vector<int> result; result.reserve(k);
        while(pq.size()){
            result.push_back(pq.top().second); pq.pop();
        }
        return result;
    }
    
private:
    typedef pair<int, int> pi;
};