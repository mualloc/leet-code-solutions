class Solution {
public:
    // TC: O(i * logi + q * logq)
    // SC: O(i + q)
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        auto queries_copy = queries;
        sort(queries_copy.begin(), queries_copy.end());
        sort(intervals.begin(), intervals.end());
        unordered_map<int, int> query_interval_map;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        int i{0};
        for(const auto& query : queries_copy) {
            for(; i < intervals.size() && query >= intervals[i][0]; ++i) min_heap.push(make_pair(intervals[i][1] - intervals[i][0] + 1, intervals[i][1]));
            while(min_heap.size() > 0 && query > min_heap.top().second) min_heap.pop();
            query_interval_map[query] = min_heap.empty() ? -1 : min_heap.top().first;
        }
        vector<int> result(queries.size());
        for(auto i{0}; i < queries.size(); ++i) result[i] = query_interval_map[queries[i]];
        return result;
    }
};
