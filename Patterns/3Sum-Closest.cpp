class Solution {
public:
    // TC: O(N^2)
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        long result{0};
        auto min_diff{INT_MAX};
        const int nums_size = nums.size();
        for(int i = 0; i < nums_size - 2; ++i) {
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            int left{i + 1}, right = nums_size - 1;
            while(left < right) {
                long curr_sum{nums[i] + nums[left] + nums[right]};
                if(curr_sum == target) return curr_sum;
                else if(auto new_diff{abs(curr_sum - target)}; new_diff < min_diff) {
                    result = curr_sum;
                    min_diff = new_diff;
                }
                curr_sum < target ? ++left : --right;
            }
        }
        return result;
    }
};
