class Solution {
public:
    // Bottom-Up
    int rob(vector<int>& nums) {
        const int count = nums.size();
        if(1 == count) return nums[0];
        
        int dp[2] = {nums[0], max(nums[0], nums[1])};
        for(int i = 2; i < count; ++i){
            int temp = max(dp[1], dp[0] + nums[i]);
            dp[0] = dp[1];
            dp[1] = temp;
        }
        
        return dp[1];
    }
};

class Solution2 {
public:
    // TC: O(N)
    // SC: O(N)
    // Top-Down
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return rob(nums, nums.size() - 1, memo);
    }
    
private:
    int rob(vector<int>& nums, int i, vector<int> & memo){
        if(i < 0) return 0;
        if(memo[i] >= 0) return memo[i];
        
        return memo[i] = max(nums[i] + rob(nums, i - 2, memo), rob(nums, i - 1, memo));
    }
};


class Solution3 {
public:
    // TC: O(2^N)
    // SC: O(N).   Implicit recursive stack
    int rob(vector<int>& nums) {
        return rob(nums, 0);
    }
 
private:
    int rob(vector<int>& nums, int i){
        if(i >= nums.size()) return 0;
        int incl = nums[i] + rob(nums, i + 2);
        int notIncl = rob(nums, i + 1);
        return max(incl, notIncl);
    }
};

class Solution4 {
public:
    // TC: O(2^N)
    // SC: O(N)     Implicit recursive stack
    int rob(vector<int>& nums) {
        return rob(nums, nums.size() - 1);
    }
 
private:
    int rob(vector<int>& nums, int i){
        if(i < 0) return 0;
        int incl = nums[i] + rob(nums, i - 2);
        int notIncl = rob(nums, i - 1);
        return max(incl, notIncl);
    }
};