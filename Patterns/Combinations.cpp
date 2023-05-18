class Solution {
public:
    // TC: O(k*n^k)
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr;
        combineHelper(n, k, 1, curr, result);
        return result;
    }

private:
    void combineHelper(int n, int k, int current, vector<int>& curr, vector<vector<int>>& result) {
        if(curr.size() == k){
            result.push_back(curr);
            return;
        }
        for(int i = current; i <= n; ++i){
            curr.push_back(i);
            combineHelper(n, k, i + 1, curr, result);
            curr.pop_back();
        }
    }

    void combineHelper2(int n, int k, int current, vector<int>& curr, vector<vector<int>>& result) {
        if(curr.size() == k){
            result.push_back(curr);
            return;
        }
        if(current > n) return;

        curr.push_back(current);
        combineHelper(n, k, current + 1, curr, result);
        curr.pop_back();
        combineHelper(n, k, current + 1, curr, result);
    }
};