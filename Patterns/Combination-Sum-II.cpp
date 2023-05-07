class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        combinationSum2Helper(candidates, target, curr, 0, result);
        return result;
    }

private:
    void combinationSum2Helper(const vector<int>& candidates, int target, vector<int>& curr, int start_index, vector<vector<int>>& result)
    {
        if(0 == target) result.push_back(curr);
        if(target < 0) return;
        for(int i = start_index; i < candidates.size(); ++i){
            if(i > start_index && candidates[i - 1] == candidates[i]) continue;
            curr.push_back(candidates[i]);
            combinationSum2Helper(candidates, target - candidates[i], curr, i + 1, result);
            curr.pop_back();
        }
    }
};

class Solution2 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        combinationSum2Helper(candidates, target, curr, 0, result);
        return result;
    }

private:
    void combinationSum2Helper(const vector<int>& candidates, int target, vector<int>& curr, int index, vector<vector<int>>& result)
    {
        if(0 == target) result.push_back(curr);
        else if(index == candidates.size()) return;
        else if(target < 0) return;
        else{
            curr.push_back(candidates[index]);
            combinationSum2Helper(candidates, target - candidates[index], curr, index + 1, result);
            curr.pop_back();
            while(index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) ++index;
            combinationSum2Helper(candidates, target, curr, index + 1, result);
        }
    }
};