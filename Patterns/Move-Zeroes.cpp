class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int valid_index{0};
        for(auto& num : nums) if(num) swap(num, nums[valid_index++]);
    }
    void moveZeroes2(vector<int>& nums) {
        auto last_valid_index{0};
        for(const auto& num : nums) if(num) nums[last_valid_index++] = num;
        fill(nums.begin() + last_valid_index, nums.end(), 0);
    }
    void moveZeroes3(vector<int>& nums) {
        stable_partition(nums.begin(), nums.end(), [](const auto& num){return 0 != num;});  
    }
};
