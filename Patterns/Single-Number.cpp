class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, [](const auto& num1, const auto& num2) {return num1 ^ num2;});
    }
};
