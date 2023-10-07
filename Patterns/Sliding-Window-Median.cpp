// https://leetcode.com/problems/sliding-window-median/solutions/96347/o-n-log-n-time-c-solution-using-two-heaps-and-a-hash-table/comments/100929
class Solution {
public:
    // TC: O(N * logN)
    // SC: O(N)
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> low;
        priority_queue<int, vector<int>, greater<int>> high;  // min heap
        unordered_map<int, int> to_be_removed;
        for(int i = 0; i < k; ++i) low.push(nums[i]);   // Always more elements than high
        for(int i = 0; i < k / 2; ++i) { high.push(low.top()); low.pop(); }
        auto get_median = [k] (const auto& low, const auto& high) { return  (k & 1) ? low.top() : ((double) low.top() + high.top()) / 2; };
        auto mov_top = [](auto& src, auto& dst) {dst.push(src.top());   src.pop();};
        auto discard_to_be_removed = [](auto& to_be_removed, auto& qeueue) {
            while(to_be_removed[qeueue.top()]) {
                --to_be_removed[qeueue.top()];
                qeueue.pop();
            }
        };

        vector<double> result;
        result.reserve(nums.size() - k + 1);
        result.emplace_back(get_median(low, high));

        const auto nums_size = nums.size();
        for(int i = k; i < nums_size; ++i){
            ++to_be_removed[nums[i - k]];
            const auto is_low_element_popped = nums[i - k] <= low.top();
            if(is_low_element_popped) {
                high.push(nums[i]);
                mov_top(high, low);
            }else {
                low.push(nums[i]);
                mov_top(low, high);
            }
            discard_to_be_removed(to_be_removed, low);
            discard_to_be_removed(to_be_removed, high);
            result.emplace_back(get_median(low, high));
        }
        return result;
    }
};


// https://leetcode.com/problems/sliding-window-median/solutions/96346/java-using-two-tree-sets-o-n-logk/comments/839062
class Solution2 {
public:
    // TC: O(N * logk)
    // SC: O(k)
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        result.reserve(nums.size() - k + 1);
        set<pair<int, int>> low;               // (val, index)
        set<pair<int, int>, greater<>> high;   // descending

        auto top = [](const auto& set) {return *(set.begin());};
        auto pop = [](auto& set) {set.erase(set.begin());};
        auto mov_top = [&top, &pop](auto& src, auto& dst) {dst.emplace(move(top(src)));  pop(src);};
        auto median = [&top, &pop] (const auto& low, const auto& high, bool is_odd) { return is_odd ? top(low).first : ((double) top(low).first + top(high).first) / 2; };

        for(int i = 0, out_of_window_index = 0; i < nums.size(); ++i) {
            low.emplace(nums[i], i);
            mov_top(low, high); // Ensure high is never smaller in size
            if(high.size() > low.size()) mov_top(high, low);
            
            if(low.size() + high.size() == k) {
                result.push_back(median(low, high, k & 1));
                if(0 == low.erase({nums[out_of_window_index], out_of_window_index})) high.erase({nums[out_of_window_index],out_of_window_index});
                ++out_of_window_index;
            }
        }       
        return result;
    }    
};
