class Solution {
public:
    // TC: O(N)
    int minSubArrayLen(int target, vector<int>& nums) {
        auto result{INT_MAX};
        auto curr_sum{0};
        for(int right = 0, left = 0; right < nums.size(); ++right) {
            curr_sum += nums[right];
            while(curr_sum >= target) {
                result = min(result, right - left + 1);
                curr_sum -= nums[left++];
            }
        }
        return result % INT_MAX;
    }
};
