class Solution {
public:
    // TC: O(N*logN)
    // SC: O(1)
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>()); 
        return nums[k - 1];
    }
};


class Solution2 {
public:
    // TC: O(N*logk)
    // SC: O(1)
    int findKthLargest(vector<int>& nums, int k) {
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater{});
        return nums[k - 1];
    }
};


class Solution3 {
public:
    // TC: O(N + k*logN)
    // SC: O(1)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> max_heap(nums.begin(), nums.end());
        while(--k) max_heap.pop();
        return max_heap.top();
    }
};


class Solution4 {
public:
    // TC: O(N^2)
    // SC: O(1)
    int findKthLargest(vector<int>& nums, int k) {
        const auto target_index{nums.size() - k};
        int begin{0}, end = nums.size() - 1;
        int index{-1};
        while(true) {
            index = partition(nums, begin, end);
            if(target_index == index) break;
            else if(index > target_index) end = index - 1;
            else begin = index + 1;
        }
        return nums[index];
    }
private:
    int partition(vector<int>& nums, int begin, int end) {
        auto pivot{nums[end]};
        int index{begin};
        while(begin < end) {
            if(nums[begin] <= pivot) swap(nums[index++], nums[begin]);
            begin++;
        }
        swap(nums[index], nums[end]);
        return index;
    }
};


class Solution5 {
public:
    // TC: O(N^2)
    // SC: O(N)
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater{});
        return nums[k - 1];
    }
};
