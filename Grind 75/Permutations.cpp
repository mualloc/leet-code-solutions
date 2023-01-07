class Solution {
public:
    // https://leetcode.com/problems/permutations/discuss/18247/My-elegant-recursive-C%2B%2B-solution-with-inline-explanation
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permute(nums, result, 0);
        return result;
    }
    
    // https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
    void permute(vector<int> &nums, vector<vector<int>> &result, int index){
        if(nums.size() <= index){
            result.push_back(nums);
        }else{
            for(int i = index; i < nums.size(); i++){
                swap(nums[i], nums[index]);
                permute(nums, result, index + 1);
                swap(nums[i], nums[index]); 
            }
        }
    }
 
    // https://leetcode.com/problems/permutations/discuss/18237/My-AC-simple-iterative-javapython-solution
    /*vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({nums[0]});
                
        for(int i = 1; i < nums.size(); i++){
            vector<vector<int>> newResult;
            for(int j = 0; j < result.size(); j++){           
                int positionCount = result[0].size() + 1;
                vector<int> newList = result[j];            
                for(int k = 0; k < positionCount; newList = result[j], k++){        // NOTE newList is reset at loop continuation
                    newList.insert(newList.begin() + k,nums[i]);    //Inserting to every possible position
                    newResult.push_back(newList);
                }
            }
            result = newResult;
        }      
        return result;
    }*/

    /*vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<vector<int>> result;
        vector<int> prefix;
        permute(nums, result, prefix, used);
        return result;
    }
    
    // https://leetcode.com/problems/permutations/discuss/179932/Beats-100-Java-with-Explanations
    void permute(vector<int> & nums, vector<vector<int>> & result, vector<int> & prefix, vector<bool> & used) {
        if(prefix.size() == nums.size()){
            result.push_back(prefix);
        }else{
            for(int i = 0; i < nums.size(); i++){
                if(true == used[i]) continue;               
                used[i] = true;
                prefix.push_back(nums[i]);
                permute(nums,result,prefix, used);
                prefix.pop_back();
                used[i] = false;
            }
        }
    }    
    
    // From CtCI
    void permute2(vector<int> & nums, vector<vector<int>> & result, vector<int> & prefix) {
        if(0 == nums.size()){
            result.push_back(prefix);
        }else{
            for(int i = 0; i < nums.size(); i++){
                prefix.push_back(nums[i]);
                vector<int> remaining = nums;
                remaining.erase(remaining.begin() + i);  
                permute2(remaining,result, prefix);
                prefix.pop_back();
            }
        }
    }*/
};