class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> result;
        backtrack(candidates, target, 0, temp, result);
        return result;
    }
    
    // O(2^target)    
    void backtrack2(const vector<int> &candidates, int target, int start, vector<int> & temp, vector<vector<int>> &result){
        if(0 == target){
            result.push_back(temp);
            return;
        }
        if(target < 0 || start >= candidates.size()) return;
        
        backtrack(candidates, target, start + 1, temp, result);       // Do not include case

        temp.push_back(candidates[start]);
        backtrack(candidates, target - candidates[start], start, temp, result);    // Include case     
        temp.pop_back();        // NOTE: Is this necessary?
    }
    
    
    void backtrack(const vector<int>& candidates, int target, int start, vector<int> & temp, vector<vector<int>> & result){
        if(0 == target){
            result.push_back(temp);
            return;
        }
        if(target < 0) return;
        
        for(int i = start; i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            int remaining = target - candidates[i];
            backtrack(candidates, remaining, i, temp, result);
            temp.pop_back();
        }        
    }
};