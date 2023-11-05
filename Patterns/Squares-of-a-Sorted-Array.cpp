class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        for(int i = nums.size() - 1, left{0}, right = nums.size() - 1; left <= right; --i)
            result[i] = abs(nums[left]) > abs(nums[right]) ? pow(nums[left++], 2) : pow(nums[right--], 2);
        return result;
    }
};
