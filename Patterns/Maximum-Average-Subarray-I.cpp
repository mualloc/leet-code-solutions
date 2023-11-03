class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        auto curr{accumulate(nums.begin(), nums.begin() + k, 0)};
        auto result{curr};
        for(int i = k; i < nums.size(); ++i) result = max(result, curr += nums[i] - nums[i - k]);
        return (double) result / k;
    }
};
