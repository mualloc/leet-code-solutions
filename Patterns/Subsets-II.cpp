class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> curr;
        subsetsWithDupHelper(nums, curr, result, 0);
        return result;
    }
    void subsetsWithDupHelper(const vector<int>& nums, vector<int>& curr, vector<vector<int>>& result, const int begin) {
        result.push_back(curr);
        for(int i = begin; i < nums.size(); ++i)
        {
            if(i > begin && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            subsetsWithDupHelper(nums, curr, result, i + 1);
            curr.pop_back();
        }
    }
};


class Solution2 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> curr;
        subsetsWithDupHelper(nums, curr, result, 0, false);
        return result;
    }

    void subsetsWithDupHelper(const vector<int>& nums, vector<int>& curr, vector<vector<int>>& result, int i, bool is_prev_incl) {
        if(i == nums.size()){
           result.push_back(curr);
        }else{
            subsetsWithDupHelper(nums, curr, result, i + 1, false);
            if(false == is_prev_incl  && i > 0 && nums[i - 1] == nums[i]) return;
            curr.push_back(nums[i]);
            subsetsWithDupHelper(nums, curr, result, i + 1, true);
            curr.pop_back();
        }
    }
};

class Solution3 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result{{}};
        vector<vector<int>> last;

        int prev = INT_MIN;
        for(const auto& num : nums)
        {
            vector<vector<int>> next_last;
            if(num == prev)
            {
                for(auto& l : last)
                {
                    l.push_back(num);
                    result.push_back(l);
                    next_last.push_back(l);
                }
            }
            else
            {
                for(const auto& r : result)
                {
                    vector<int> c = r;
                    c.push_back(num);
                    next_last.push_back(c);
                }
                result.insert(result.end(), next_last.begin(), next_last.end());
            }
            next_last.swap(last);
            prev = num;
        }

        return result;
    }
};