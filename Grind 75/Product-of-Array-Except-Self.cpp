class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 1);
        
        for(int i = 1; i < size; i++){
            result[i] = result[i - 1] * nums[i -1];
        }
        int postfix = 1;
        for(int i = size - 1; i >= 0; i--){
            result[i] *= postfix;
            postfix *= nums[i];
        }
        
        return result;
    }

    /*vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() < 2) return nums;
        
        size_t size = nums.size();          // Acts as prefix
        vector<int> result(size, 1);        // Acts as suffix
        
        result[0] = nums[0];
        for(int i = 1; i < size; i++){      // Suffix array construction
            result[i] = result[i - 1] * nums[i];
        }
        
        for(int i = size - 2; i >= 0; i--){     // Prefix array construction
            nums[i] = nums[i + 1] * nums[i];
        }
        
        int last = result[size - 1 - 1];
        for(int i = size - 1 - 1; i >0 ; i--){
            result[i] = result[i - 1] * nums[i + 1];
        }
        result[0] = nums[1];
        result[size - 1] = last; 
        
        return result;
    }*/
};