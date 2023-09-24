class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    int minKBitFlips(vector<int>& nums, int k) {
        int result = 0;
        const auto flip = [] (int num, int flip_count) {return num ^ (flip_count & 1);};
        int current_flip_count = 0;
        const int nums_size = nums.size();
        for(int i = 0; i < nums_size; ++i) {
            if(i - k >= 0 && nums[i - k] > 1) {
                --current_flip_count;
                nums[i - k] -= 2;
            }
            if(0 == flip(nums[i], current_flip_count)){
                if(i <= nums_size - k) {
                    ++current_flip_count;
                    nums[i] += 2;
                    ++result;
                }else return -1;
            }
        }
        return result; 
    }
};


class Solution2 {
public:
    // TC: O(k*N)
    // SC: O(1)
    int minKBitFlips(vector<int>& nums, int k) {
        int result = 0;
        const int nums_size = nums.size();
        for(int i = 0; i < nums_size; ++i) {
            if(0 == nums[i]) {
                if(i + k > nums_size) return -1;
                for(int j = i; j < i + k; ++j) nums[j] ^= 1;    // Toggle the bit
                ++result;
            }
        }
        return result;
    }
};
