// https://leetcode.com/problems/burst-balloons/solutions/655397/C++-DP-solution-with-very-detailed-explanation-starting-from-DFS/
class Solution {
public:
	// TC: O(n^3)
	// SC: O(n^2)
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

        for(auto window_size{1}; window_size <= nums.size() - 2; ++window_size) {
            for(auto left{1}, right{left + window_size - 1}; right < nums.size() - 1; ++left, ++right) {
                for(auto last_to_burst{left}; last_to_burst <= right; ++last_to_burst) {
                    auto current{nums[left - 1] * nums[last_to_burst] * nums[right + 1] + dp[left][last_to_burst - 1] + dp[last_to_burst + 1][right]};
                    dp[left][right] = max(dp[left][right], current);
                }
            }
        }
        return dp[1][nums.size() - 2];
    }
};


class Solution2 {
public:
	// TC: O(n^3)
	// SC: O(n^2)
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return dfs(0, nums.size() - 1, nums, dp);
    }
private:
    int dfs(int left, int right, const vector<int>& nums, vector<vector<int>>& dp){
        if(left > right) return 0;
        if(-1 != dp[left][right]) return dp[left][right];
        for(auto i{left}; i <= right; ++i) {
            auto left_coin{0 == left ? 1 : nums[left - 1]};
            auto right_coin{nums.size() - 1 == right ? 1 : nums[right + 1]};
            auto left_to_right_coin_sum{left_coin * nums[i] * right_coin + dfs(left, i - 1, nums, dp) + dfs(i + 1, right, nums, dp)};
            dp[left][right] = max(dp[left][right], left_to_right_coin_sum);
        }
        return dp[left][right];
    }
};
