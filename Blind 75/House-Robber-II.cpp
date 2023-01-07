class Solution {
public:
    int rob(vector<int>& nums) {
        if(1 == nums.size()) return nums[0];
        return max(rob(nums, 0, nums.size() - 2), rob(nums, 1, nums.size() - 1));
    }
    
private:
    int rob(vector<int>& nums, int start, int end) {        
        int prev = 0, curr = 0;
        for(int i = start; i <= end; ++i){
            int temp = prev + nums[i];
            prev = curr;
            curr = max(prev, temp);
        }
        return curr;
    }
};