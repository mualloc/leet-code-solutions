class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    int firstMissingPositive(vector<int>& nums) {
        const auto nums_size = nums.size();
        for(int i = 0; i < nums_size;){
            if(nums[i] <= 0 || nums[i] > nums_size || nums[i] == nums[nums[i] - 1]) ++i;
            else swap(nums[nums[i] - 1], nums[i]);
        }
        for(int i = 0; i < nums_size; ++i) if(i + 1 != nums[i]) return i + 1;
        return nums_size + 1;
    }
};


class Solution2 {
public:
    // TC: O(N)
    // SC: O(1)
    int firstMissingPositive(vector<int>& nums) {
        const int nums_size = nums.size();
        transform(nums.begin(), nums.end(), nums.begin(), [nums_size](auto num) {return num <= 0 ? nums_size + 1 : num;});

        for(const auto& num : nums) {
            if(auto abs_num = abs(num); abs_num <= nums_size) nums[abs_num - 1] = -abs(nums[abs_num - 1]);
        }

        for(int i = 0; i < nums_size; ++i) if(nums[i] > 0) return i + 1;
        return nums_size + 1;
    }
};
