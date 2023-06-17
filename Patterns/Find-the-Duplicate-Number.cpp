// https://leetcode.com/problems/find-the-duplicate-number/solutions/72846/my-easy-understood-solution-with-o-n-time-and-o-1-space-without-modifying-the-array-with-clear-explanation/comments/75573
// https://leetcode.com/problems/find-the-duplicate-number/solutions/72846/my-easy-understood-solution-with-o-n-time-and-o-1-space-without-modifying-the-array-with-clear-explanation/comments/75491
class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast != slow);

        slow = 0;
        do{
            slow = nums[slow];
            fast = nums[fast];
        }while(fast != slow);
        
        return slow;
    }
};

// https://leetcode.com/problems/find-the-duplicate-number/solutions/560089/c-4-different-solutions-beats-100-detailed-explanantion/
class Solution2 {
public:
    // TC: O(N * logN)
    // SC: O(1)
    int findDuplicate(vector<int>& nums) {
        const int nums_len = nums.size();
        int low = 1, high = nums.size();
        while(low < high){
            int guess = low + ((high - low) >> 1);
            int values_leq_guess_counter = 0;
            for(int i = 0; i < nums_len; ++i) values_leq_guess_counter += nums[i] <= guess;
            if(values_leq_guess_counter > guess) high = guess;
            else low = guess + 1;
        }
        return low;
    }
};

// Invalid solution!!
class Solution3 {
public:
    int findDuplicate(vector<int>& nums) {
        const int len = nums.size();
        for(int i = 0; i < len; ++i){
            const int swapIndex = abs(nums[i]);
            if(nums[swapIndex] < 0) return abs(nums[i]);
            nums[swapIndex] = -nums[swapIndex];
        }
        return 0;
    }
};
