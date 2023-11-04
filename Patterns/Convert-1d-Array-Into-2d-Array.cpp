class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result;
        if(original.size() == m * n) for(auto it = original.begin(); it != original.end(); it += n) result.push_back({it, it + n});
        return result;
    }
};
