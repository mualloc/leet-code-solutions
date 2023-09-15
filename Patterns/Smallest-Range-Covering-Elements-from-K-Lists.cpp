class Solution {
public:
    // TC: O((n * k) * logk)
    // SC: O(logk)
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using int_pos_t = pair<int, pair<vector<int>::iterator, vector<int>::iterator>>;
        priority_queue<int_pos_t, vector<int_pos_t>, greater<>> min_heap;

        int high = INT_MIN;
        for(auto& list : nums) {
            high = max(high, list[0]);
            min_heap.push(make_pair(list[0], make_pair(list.begin(), list.end())));
        }

        int low = min_heap.top().first;
        vector<int> result{low, high};
        while(nums.size() == min_heap.size()){
            auto min_element = min_heap.top(); min_heap.pop(); 
            low = min_element.first;
            if(high - low < result[1] - result[0]) result[0] = low, result[1] = high;
            auto next_it = next(min_element.second.first);
            auto min_list_end = min_element.second.second;
            // List with min element is exhausted! No way to include an element from that list anymore!  
            if(next_it == min_list_end) break;   
            high = max(*next_it, high);
            min_heap.push(make_pair(*next_it, make_pair(next_it, min_list_end)));
        }
        return result;
    }
};
