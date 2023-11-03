class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(const auto& num : nums) {
            auto abs_val{abs(num)};
            nums[abs_val - 1] = -abs(nums[abs_val - 1]);
        }
        vector<int> result;
        result.reserve(count_if(nums.begin(), nums.end(), [](int num){return num > 0;}));
        for(int i{0}; i < nums.size(); ++i) if(nums[i] > 0) result.push_back(i + 1);
        return result;
    }
};
