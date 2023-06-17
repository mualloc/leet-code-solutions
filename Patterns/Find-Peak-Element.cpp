class Solution {
public:
    // TC: O(logN)
    // SC: O(logN)
    int findPeakElement(vector<int>& nums) {
        const int nums_len = nums.size();
        int low = 0, high = nums.size() - 1;
        return findPeakElementHelper(nums, 0, nums.size() - 1);
    }
private:
    int findPeakElementHelper(const vector<int>& nums, int low, int high){
        if(low == high) return low;
        int mid = low + ((high - low) >> 1);
        if(nums[mid + 1] > nums[mid]) return findPeakElementHelper(nums, mid + 1, high);
        else return findPeakElementHelper(nums, low, mid);
    }
};

// https://leetcode.com/problems/find-peak-element/solutions/1334425/c-simple-and-easy-solutions-from-binary-search-to-a-cool-one-liner-explained/
class Solution2 {
public:
    int findPeakElement(vector<int>& nums) {
        const int nums_len = nums.size();
        int low = 0, high = nums.size() - 1;
        while(low < high){
            int mid = low + ((high - low) >> 1);
            if(nums[mid + 1] > nums[mid]) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};

// https://leetcode.com/problems/find-peak-element/solutions/50232/find-the-maximum-by-binary-search-recursion-and-iteration/comments/117565
class Solution3 {
public:
    int findPeakElement(vector<int>& nums) {
        const int nums_len = nums.size();
        int low = 0, high = nums.size() - 1;
        int mid = low + (high - low) / 2;
        do{
            if(mid > 0 && nums[mid - 1] > nums[mid]) high = mid - 1;
            else if(mid + 1 < nums_len && nums[mid + 1] > nums[mid]) low = mid + 1;
            else return mid;
            mid = low + ((high - low) >> 1);
        }while(low < high);

        return low;
    }
};
