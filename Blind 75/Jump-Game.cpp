class Solution {
public:
    // Greedy
    // TC: O(N)
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        const int target = nums.size() - 1;
        
        for(int i = 0; i <= maxReach; i++){
            maxReach = max(maxReach, i + nums[i]);
            if(maxReach >= target) return true;
        }
        return false;
    }
};


class Solution2 {
public:
    // Greedy
    // TC: O(N)
    bool canJump(vector<int>& nums) {
        int targetIndex = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; --i){
            if(i + nums[i] >= targetIndex) targetIndex = i;
        }
        return 0 == targetIndex;
    }
};


class Solution3 {
public:
    // Top down DP
    // TC: O(N^2)
    // SC: O(N)
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[nums.size() - 1] = true;
        
        for(int i = nums.size() - 2; i >= 0; --i){
            for(int j = 1; j <= nums[i]; ++j){
                if(true == dp[i + j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};


class Solution4 {
public:
    // TC: O(N^2)
    // SC: O(N)
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        dp[nums.size() - 1] = true;
        
        return canJumpHelper(nums, 0, dp);
    }
    
private:
    int canJumpHelper(const vector<int>& nums, int currIndex, vector<int> & dp){
        if(-1 != dp[currIndex]) return dp[currIndex];
        
        for(int i = 1; i <= nums[currIndex]; i++){
            if(dp[currIndex] = canJumpHelper(nums, currIndex + i, dp)) return dp[currIndex];
        }
        
        return dp[currIndex] = 0;
    }
};


class Solution5 {
public:
    bool canJump(vector<int>& nums) {
        if(1 == nums.size()) return true;
        
        unordered_set<int> toBeJumpIndexes({0});
        vector<bool> jumped(nums.size(), false);
        jumped[0]= true;
        
        const int target = nums.size() - 1;
        while(false == toBeJumpIndexes.empty()){
            unordered_set<int> nextJumpIndexes;
            for (int currentIndex : toBeJumpIndexes) {
                for(int i = 1; i <= nums[currentIndex]; i++){
                    const int nextJumpIndex = i + currentIndex;
                    if(nextJumpIndex == target) return true;
                     if(false == jumped[nextJumpIndex]){
                        nextJumpIndexes.insert(nextJumpIndex);
                        jumped[nextJumpIndex] = true;
                    }
                }
            }
            toBeJumpIndexes.swap(nextJumpIndexes);
        }
               
        return false;
    }
};