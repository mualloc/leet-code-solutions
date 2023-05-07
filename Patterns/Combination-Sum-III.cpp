class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> curr;
        combinationSum3Helper(k, n, 1, curr, result);
        return result;
    }

private:
    void combinationSum3Helper(int k, int n, int start_index, vector<int>& curr, vector<vector<int>>& result)
    {
        if(0 == n && 0 == k) result.push_back(curr);
        else if(0 == k) return;
        else {
            for(int i = start_index; i <= 9; ++i){
                if(i > n) return;
                curr.push_back(i);
                combinationSum3Helper(k - 1, n - i, i + 1, curr, result);
                curr.pop_back();
            }
        }
    }
};