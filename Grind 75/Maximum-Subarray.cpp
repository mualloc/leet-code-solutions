// BUNA BAK: https://leetcode.com/problems/maximum-subarray/discuss/1595195/C%2B%2BPython-7-Simple-Solutions-w-Explanation-or-Brute-Force-%2B-DP-%2B-Kadane-%2B-Divide-and-Conquer

class Solution {
public:
    /*int maxSubArray(vector<int>& nums) {
        int max = pow(10,4) * -1;
        int currentSum = 0;
        
        for(const auto & num : nums){
            currentSum += num;
            if(currentSum >= max){
                max = currentSum;
            } 
            if(currentSum < 0){
                currentSum = 0;     
            }
        }
        return max;
    }*/
    
    int max(int t1, int t2, int t3){
        return std::max(std::max(t1, t2), t3);
    }
    
    /*int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
    
    int maxSubArray(vector<int>& nums, int low, int high) {
        if(low > high){
            return INT_MIN;
        }
        int mid = low + (high - low) / 2;
        int leftSum = 0, rightSum = 0, currentSum = 0;
        
        for(int i = mid - 1;  i >= low; i--){
            currentSum += nums[i];
            leftSum = std::max(leftSum, currentSum);
        }
        currentSum = 0;
        for(int i = mid + 1;  i <= high; i++){
            currentSum += nums[i];
            rightSum = std::max(rightSum, currentSum);
        }
        return 
            max(maxSubArray(nums, low, mid - 1), maxSubArray(nums, mid + 1, high), leftSum + rightSum + nums[mid]);                     
    }*/
    
    int maxSubArray(vector<int>& nums) {
        vector<int> pre, suf;
        pre = suf = nums;
        for(int i = 1; i < nums.size();i++){
            pre[i] += std::max(0, pre[i -1]);
        }
        for(int i = nums.size() - 2; i >= 0; i--){
            suf[i] += std::max(0, suf[i + 1]);
        }
        return maxSubArray(nums, pre, suf, 0, nums.size() - 1);
    }
    
    int maxSubArray(vector<int>& nums, vector<int>& pre, vector<int>& suf, int start, int end) {
        if(start == end){
            return nums[start];
        }
        int mid = start + (end - start) / 2;
        // NOTE: Neden sol taraf için end 'mid'??  Öncekinde sol taraf için end 'mid-1' idi???
        //                                            vvv (mid - 1)???
        return max(maxSubArray(nums, pre, suf, start, mid), maxSubArray(nums, pre, suf, mid + 1, end), pre[mid] + suf[mid + 1]);
    }
};