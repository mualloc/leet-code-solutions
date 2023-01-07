class Solution {
public:
    // TC: O(n)
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for(int i = 0; i < nums.size(); ++i) result += i - nums[i];
        return result;
    }
};


class Solution2 {
public:
    // TC: O(2 * n)
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for(size_t i = 0; i < nums.size(); ++i) result ^= nums[i] ^ i;
        return result;
    }
};


class Solution3 {
public:
    int missingNumber(vector<int>& nums) {
        const int maxNum = nums.size();
        
        bool maxNumberExists = false;
        bool zeroNumExists = false;
        for(int i = 0; i < maxNum; ++i){
            uint absNum = abs(nums[i]);
            if(maxNum == absNum) maxNumberExists = true;
            else if(0 == nums[absNum]) zeroNumExists = true;
            else nums[absNum] *= -1;
        }
       
        if(!maxNumberExists) return maxNum;
        for(int i = 0; i < maxNum; ++i){
             if(nums[i] > 0) return i;
             if(0 == nums[i] && false == zeroNumExists) return i;
        }
        
        return -1;  // Will not execute
    }
};