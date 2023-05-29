class Solution2 {
public:
    // TC: O(N * T)
    // SC: O(T)
    int combinationSum4(vector<int>& nums, int target) {
        // Note 'long' and modulus to INT_MAX since for some test case, intermediate result, e.g. dp[target - 2], might exceed INT_MAX.
        vector<long> dp(target + 1, 0);       
        dp[0] = 1;
        for(int sub_target = 1; sub_target <= target; ++sub_target){
            for(const auto& num : nums) 
                if(sub_target >= num) dp[sub_target] += dp[sub_target - num] % INT_MAX/*Note this!!*/;
        }
        return dp.back();
    }
};

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> cache(target + 1, -1);
        cache[0] = 1;
        combinationSum4Helper(nums, target, cache);
        return cache.back();
    }
private:
    int combinationSum4Helper(const vector<int>& nums, int target, vector<int>& cache){
        if(-1 != cache[target]) return cache[target];
        cache[target] = 0;
        for(const auto& num : nums) {
            if(num <= target) cache[target] += combinationSum4Helper(nums, target - num, cache);
        }
        return cache[target];
    }
};
