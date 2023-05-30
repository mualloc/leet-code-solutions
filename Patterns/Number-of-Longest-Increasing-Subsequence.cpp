// Recursive solution: https://github.com/neetcode-gh/leetcode/blob/0cc7ed43f7718c90279949c58055b1482d027506/python/0673-number-of-longest-increasing-subsequence.py#L2
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<int>> cache(nums.size(), {1,1}); // (index, {longest_length, count})
        int longest_length = 1;
        int result = 1;
        for(int i = 1; i < nums.size(); ++i) {
            for(int j = 0; j <= i; ++j) {
                if(nums[i] > nums[j]){
                    if(cache[j][0] + 1 > cache[i][0]){
                        cache[i][0] = cache[j][0] + 1;
                        cache[i][1] = cache[j][1];
                    }else if(cache[j][0] + 1 == cache[i][0]) cache[i][1] += cache[j][1];
                }
            }
            if(cache[i][0] > longest_length){
                longest_length = cache[i][0];
                result = cache[i][1];
            }else if(cache[i][0] == longest_length) result += cache[i][1];
        }
        return result;
    }
};

class Solution2 {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<int>> cache(nums.size(), {1,1}); // (index, {longest_length, count})
        int longest_length = 0;
        int result = 0;
        for(int i = nums.size() - 1; i >= 0; --i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                if(nums[i] < nums[j]) {
                    if(cache[j][0] + 1 > cache[i][0]) {
                        cache[i][0] = cache[j][0] + 1;
                        cache[i][1] = cache[j][1];
                    }else if(cache[j][0] + 1 == cache[i][0]) cache[i][1] += cache[j][1];
                }
            }
            if(cache[i][0] > longest_length){
                longest_length = cache[i][0];
                result = cache[i][1];
            }else if(cache[i][0] == longest_length) result += cache[i][1];            
        }
        return result;
    }
};
