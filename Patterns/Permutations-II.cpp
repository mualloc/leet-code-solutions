class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        permuteUniqueHelper(nums, 0, result);
        return result;
    }

    void permuteUniqueHelper(vector<int>& nums, int begin_index, vector<vector<int>>& result)
    {
        unordered_set<int> used;
        if(begin_index == nums.size()){
            result.push_back(nums);
        }else{
            for(int l = begin_index; l < nums.size(); ++l){
                if(used.end() != used.find(nums[l])) continue;
                used.insert(nums[l]);
                swap(nums[l], nums[begin_index]);
                permuteUniqueHelper(nums, begin_index + 1, result);
                swap(nums[l], nums[begin_index]);
            }
        }
    }
};


class Solution2 {
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