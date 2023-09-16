class Solution {
public:
    // TC: O(N)
    // SC: O(k)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> index_deque;
        vector<int> result;
        result.reserve(nums.size() - k + 1);
        const int nums_size = nums.size();
        for(int i = 0; i < nums_size; ++i){
            if(index_deque.size() > 0 && index_deque.front() == i - k) index_deque.pop_front();
            while(index_deque.size() > 0 && nums[index_deque.back()] < nums[i]) index_deque.pop_back();
            index_deque.push_back(i);
            if(i  >= k - 1) result.push_back(nums[index_deque.front()]);
        }
        return result;
    }
};


class Solution2 {
public:
    // TC: O(N)
    // SC: O(k)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deque;   // Monotonically decreasing queue
        vector<int> result(nums.size() - k + 1, 0);
        int result_index = 0;
        int nums_index = 0;
        auto push_deque = [&deque] (int new_num) {
            while(deque.size() > 0 && deque.back() < new_num) deque.pop_back();
            deque.push_back(new_num);
        };
        deque.push_back(nums[nums_index++]);
        while(nums_index < k) push_deque(nums[nums_index++]);
        result[result_index++] = deque.front();

        while(nums_index < nums.size()){
            if(deque.front() == nums[nums_index - k]) deque.pop_front();
            push_deque(nums[nums_index++]);
            result[result_index++] = deque.front();
        }
        return result;
    }
};
