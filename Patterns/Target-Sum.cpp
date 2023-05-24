class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n+1);
        dp[0][0]=1;
        for(int i=0;i<n;i++)
            for(auto &p:dp[i]) {
                dp[i+1][p.first+nums[i]] += p.second; 
                dp[i+1][p.first-nums[i]] += p.second;
        }
        return dp[n][S];
    }
};

class Solution {
public:
    using cache_t = vector<unordered_map<int, int>>;
    int findTargetSumWays(vector<int>& nums, int target) {
        cache_t cache(nums.size());
        return findTargetSumWaysHelper(0, cache, nums, target, 0);
    }

private:
    int findTargetSumWaysHelper(int index, cache_t& cache, vector<int>& nums, const int target, int curr_sum){
        if(nums.size() == index) return curr_sum == target;
        
        if(cache[index].end() != cache[index].find(curr_sum)) return cache[index][curr_sum];
        return cache[index][curr_sum] = findTargetSumWaysHelper(index + 1, cache, nums, target, curr_sum - nums[index]) + findTargetSumWaysHelper(index + 1, cache, nums, target, curr_sum + nums[index]);
    }
};

class Solution3 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> curr(1, 0);
        for(const auto& num : nums){
            vector<int> temp;
            temp.reserve(curr.size() * 2);
            for(const auto& c : curr){
                temp.push_back(c - num);
                temp.push_back(c + num);
            }
            temp.swap(curr);
        }
        return std::count_if(curr.begin(), curr.end(), [target](int i) {return i == target;});
    }
};

