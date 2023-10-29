// https://leetcode.com/problems/max-consecutive-ones-iii/solutions/719833/python3-sliding-window-with-clear-example-explains-why-the-soln-works/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        auto left{0}, right{0};
        for(; right < nums.size(); ++right) {
            if(0 == nums[right]) --k;
            if(k < 0 && 0 == nums[left++]) ++k;
        }
        return right - left;
    }
};


class Solution2 {
public:
    // TC: O(N)
    // SC: O(1)
    int longestOnes(vector<int>& nums, int k) {
        auto result{0};
        for(int left{0}, right{0}; right < nums.size(); ++right) {
            if(0 == nums[right]) --k;
            while(k < 0) k += !nums[left++];
            result = max(result, right - left + 1);
        }
        return result;
    }
};
