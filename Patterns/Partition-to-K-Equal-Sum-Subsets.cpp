// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/solutions/905981/Iterative-DP-deep-analysis:-4-solutions-(2-ways-of-bit-masking-2-ways-of-backtracking)/comments/987737
class Solution {
public:
    // TC: O(n*2^n)
    // SC: O(2^n)
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        const long sum_of_elements = accumulate(nums.begin(), nums.end(), 0);
        if(sum_of_elements % k) return false;
        const long target = sum_of_elements / k;
        const size_t subset_count = 1 << nums.size();
        vector<unsigned long> dp(subset_count, -1);
        dp[0] = 0;
        for(size_t i = 0; i < subset_count; ++i){
            if(-1 == dp[i]) continue; 
            for(size_t j = 0; j < nums.size(); ++j){
                bool is_not_in_subset = 0 == (i & (1 << j));
                if(is_not_in_subset){
                    long new_sum = dp[i] + nums[j];
                    const size_t new_subset_index = i | (1 << j);
                    if(new_sum <= target) dp[new_subset_index] = new_sum == target ? 0 : new_sum;
                }
            }
        }
        return 0 == dp.back();
    }
};

class Solution2 {
public:
    // TC: O(n^k)
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        const long sum_of_elements = accumulate(nums.begin(), nums.end(), 0);
        if(sum_of_elements % k) return false;
        const long target_subset_sum = sum_of_elements / k;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        return canPartitionKSubsetsHelper(nums, k, 0, 0, target_subset_sum, used);
    }
private:
    bool canPartitionKSubsetsHelper(vector<int>& nums, int k, int index, int current_sum, const long target_sum, vector<bool>& used) {
        if(1 == k) return true;
        if(target_sum == current_sum){
            return canPartitionKSubsetsHelper(nums, k - 1, 0, 0, target_sum, used);
        }
        for(int i = index; i < nums.size(); ++i){
            const int new_some = current_sum + nums[i];
            if(new_some > target_sum) break;
            if(true == used[i]) continue;
            used[i] = true;
            if(canPartitionKSubsetsHelper(nums, k, i + 1, new_some, target_sum, used)) return true;
            used[i] = false;
        }
        return false;
    }
};