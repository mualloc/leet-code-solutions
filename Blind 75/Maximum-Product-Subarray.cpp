class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN;
        
        int currMin = 1, currMax = 1;
        for(int & num : nums){
            int tempMax = currMax * num, tempMin = currMin * num;
            currMax = max(num, max(tempMax, tempMin));
            currMin = min(num, min(tempMax, tempMin));
            result = max(result, currMax);
        }
        
        return result;
    }
};


class Solution2 {
public:
    // TC: O(N)
    int maxProduct(vector<int>& nums){
        int result = INT_MIN;
        
        for(int i = 0, prod = 1; i < nums.size(); ++i){
            prod *= nums[i];
            result = max(result, prod);
            if(0 == prod) prod = 1;
        }
        for(int i = nums.size() - 1, prod = 1; i >= 0; --i){
            prod *= nums[i];
            result = max(result, prod);
            if(0 == prod) prod = 1;
        }
        
        return result;
    }
};


class Solution3 {
public:
    // TC: O(N^2)
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            int temp = 1;
            for(int j = i; j < nums.size(); ++j){
                temp *= nums[j];
                if(temp > result) result = temp;
                if(0 == nums[j]) break;
            }
        }
        return result;
    }
};