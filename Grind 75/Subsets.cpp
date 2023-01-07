class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.reserve(1 << nums.size());
        vector<int> curr;
        subsetsHelper(0, nums, curr, result);
        return result;
    }

private:
    void subsetsHelper(int start, vector<int>& nums, vector<int> & current, vector<vector<int>> & result){
        result.push_back(current);
        
        for(int i = start; i < nums.size(); i++){
            current.push_back(nums[i]);
            subsetsHelper(i + 1, nums, current, result);
            current.pop_back();
        }
    }
};

// TC : O(N*(2^N))
// SC : O(N) or O(N^2): Not counting return value!
/******************************************************************************************************/
class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.reserve(1 << nums.size());
        subsetsHelper(0, nums, vector<int>(), result);
        return result;
    }
    
private:
    void subsetsHelper(int index, vector<int>& nums, vector<int> current, vector<vector<int>> & result) {
        if(nums.size() == index) { result.push_back(current); return; }
        
        subsetsHelper(index + 1, nums, current, result);               
        current.push_back(nums[index]);
        subsetsHelper(index + 1, nums, current, result);               
    }
};


class Solution3 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int numOfSubsets = 1 << nums.size();
        result.reserve(numOfSubsets);
        
        result.push_back({});
        for(int i = 0; i < nums.size(); i++){
            int currentNumOfSubsets = result.size();
            for(int j = 0; j < currentNumOfSubsets; j++){
                result.push_back(result[j]);
                result.back().push_back(nums[i]);
            }    
        }
        return result;
    }
};

class Solution4 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int numOfSubsets = 1 << nums.size();
        vector<vector<int>> result(numOfSubsets);

        for(size_t i = 0; i < numOfSubsets; i++){
            for(size_t j = 0; j < 32; j++){
                unsigned char bit = (i >> j) & 1;
                if(bit) result[i].push_back(nums[j]);
            }
        }   
        return result;
    }
};

class Solution5 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int numOfSubsets = 1 << nums.size();
        vector<vector<int>> result(numOfSubsets);
        
        for(size_t i = 1; i < numOfSubsets; i++){
            int subset = i;
            while(subset){
                result[i].push_back(nums[lastSetBitIndex(subset)]);
                subset = unsetLastSetBit(subset);
            }
        }
        return result;
    }
    
private:
    int lastSetBitIndex(unsigned num){
        if(0 == num) return -1;
        return mylog2(num & (~num + 1)); 
    }
    int unsetLastSetBit(unsigned num){
        if(0 == num) return 0;
        return num & (num - 1);
    }
    int mylog2(int num){
        int result = 0;
        while(num >>= 1) result++;
        return result;
    }
};


class Solution6 {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        int numsSize = nums.size();
        int numOfSubsets = 1 << numsSize;
        vector<vector<int>> result(numOfSubsets);
        
        for(int i = 0; i < numsSize; i++){
            for(int j = 0; j < numOfSubsets; j++){
                if((j >> i) & 1){
                    result[j].push_back(nums[i]);
                }
            }
        }
        return result;
    }
};