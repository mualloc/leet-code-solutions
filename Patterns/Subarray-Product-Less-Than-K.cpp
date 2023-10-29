class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long curr_product{1L};
        int left{0};
        int result{0};
        for(int right{0}, nums_size = nums.size(); right < nums_size; ++right){
            curr_product *= nums[right];
            while(left <= right && curr_product >= k) curr_product /= nums[left++];
            result += right - left + 1;            
        }
        return result;
    }
};
