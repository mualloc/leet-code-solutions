class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        permuteUniqueHelper(nums, used, result, curr);
        return result;
    }

    void permuteUniqueHelper(const vector<int>& nums, vector<bool> used, vector<vector<int>>& result, vector<int>& curr)
    {
        if(curr.size() == nums.size()) {
            result.push_back(curr);
        }else{
            for(int i = 0; i < nums.size(); ++i) {
                if(true == used[i]) continue;
                if(i > 0 && nums[i] == nums[i - 1] && false == used[i - 1]) continue;
                curr.push_back(nums[i]);
                used[i] = true;
                permuteUniqueHelper(nums, used, result, curr);
                curr.pop_back();
                used[i] = false;
            }
        }
    }
};