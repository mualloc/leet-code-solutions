/*class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum_of_elems = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum_of_elems & 1) return false;  // Check if odd
        int target { sum_of_elems / 2 };
    
        unordered_set<int> sums {0};
        for(int num : nums){
            unordered_set<int> temp { sums };
            for(auto it : temp){
                int curr { it + num };
                if(curr == target) return true;
                else sums.insert(curr);
            }
        }
        return false;
    }
};*/

class Solution {
public:
	// 1D Knapsack
    bool canPartition(vector<int>& nums) {
        int sum_of_elems = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum_of_elems & 1) return false;  // Check if odd
        const int target { sum_of_elems / 2 };
              
        //sort(nums.begin(), nums.end());
        vector<bool> dp(target + 1, false); dp[0] = true;
        for(const int num : nums){
            for(int sum = target; sum >= 1; --sum){
                if(sum >= num){
                    dp[sum] = dp[sum] || dp[sum - num];
                }//else break;
            }
        }
        return dp[target];
    }
    
	// 2D Knapsack
    bool canPartition2(vector<int>& nums) {
        int sum_of_elems = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum_of_elems & 1) return false;  // Check if odd
        int target { sum_of_elems / 2 };
        
        vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));
        dp[0][0] = true;
        for(size_t i = 1; i < dp.size(); i++) dp[i][0] = true;
        for(size_t j = 1; j < dp[0].size(); j++) dp[0][j] = false;
                
        for(int i = 1; i < dp.size(); ++i){
            for(int j = 1; j < dp[0].size(); ++j){
                dp[i][j] = dp[i - 1][j];
                if(j >= nums[i - 1]) { dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]]; }
            }
        }

        return dp[nums.size()][target];
    }
};


/*class Solution {
public:
    // DFS + Memorization
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;  // Check if odd
        const int target { sum / 2 };
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        //for(size_t i = 0; i < nums.size(); i++) dp[i][0] = 1;
        return canPartitionHelper(0, target, nums, dp);
    }
    
    bool canPartitionHelper(int startIndex, int target, vector<int>& nums, vector<vector<int>> & dp){
        if(nums.size() == startIndex) return false;
        if(target < 0) return false;
        if(0 == target) return true;
        if(-1 != dp[startIndex][target]) return dp[startIndex][target];
        
        if(canPartitionHelper(startIndex + 1, target - nums[startIndex], nums, dp) 
           || canPartitionHelper(startIndex + 1, target, nums, dp)){
            return dp[startIndex][target] = 1;
        }  
        return dp[startIndex][target] = 0;
    }
};*/


/*class Solution {
public:
    // Bitmask
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;  // Check if odd
        const int target = sum / 2;
        bitset<kMaxTarget> dp(1);   // 0 is always achievable => dp[0] = 1
        
        for(const int num : nums){
            dp |= dp << num; 
        }
        return dp[target];
    }
private:
    enum Constants{
        kMaxLength = 200,
        kMaxNum = 100,
        kMaxTarget = kMaxLength * kMaxNum + 1,  // +1 for zero.
    };
};*/