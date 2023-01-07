class Solution {
public:
    // TC: O(N^2)
    // SC: O(N)    
    int lengthOfLIS(vector<int>& nums) {        
        vector<int> dp(nums.size(), 1);
        
        int result = 1;
        for(int i = nums.size() - 2; i >= 0; --i){
            for(int j = i + 1; j < nums.size(); ++j){
                if(nums[i] < nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        
        return result;
    }
};


class Solution2 {
public:
    // TC: O(2^N)
    // SC: O(N)
    int lengthOfLIS(vector<int>& nums) {        
        return lengthOfLISHelper(nums, 0, INT_MIN);
    }
    
private:
    int lengthOfLISHelper(const vector<int>& nums, int i, int prev){
        if(i == nums.size()) return 0;
        
        int take = 0;
        if(prev < nums[i]) take = 1 + lengthOfLISHelper(nums, i + 1, nums[i]);
        int dontTake = lengthOfLISHelper(nums, i + 1, prev);
        
        return max(take, dontTake);
    }
};