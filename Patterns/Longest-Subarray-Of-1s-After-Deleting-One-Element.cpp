// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/submissions/1086888136/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result{0}, prev{0}, curr{0};
        for(const auto& num : nums) {
            if(num) result = max(result, ++curr + prev);
            else prev = curr, curr = 0;
        }
        return result - (nums.size() == result);
    }
};


class Solution2 {
public:
    int longestSubarray(vector<int>& nums) {
        int left{0}, right{0}, k{1};
        for(const auto nums_size = nums.size(); right < nums_size; ++right) {
            if(0 == nums[right]) --k;
            if(k < 0 && 0 == nums[left++]) ++k;
        }
        return right - left - 1;
    }
};


class Solution3 {
public:
    int longestSubarray(vector<int>& nums) {
        int result{0};
        for(int left{0}, right{0}, zero_count{0}, nums_size = nums.size(); right < nums_size; ++right) {
            zero_count += 0 == nums[right];
            while/*if*/(zero_count > 1) zero_count -= 0 == nums[left++];
            result = max(result, right - left);
        }
        return result;
    }
};
