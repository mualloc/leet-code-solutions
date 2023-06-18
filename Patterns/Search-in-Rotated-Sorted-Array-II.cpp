class Solution {
public:
    // TC: O(N)
    bool search(vector<int>& nums, int target) {
        const int nums_size = nums.size();
        int low = 0, high = nums_size - 1;
        while(low < high){
            while(low < high && nums[low] == nums[low + 1]) ++low;
            while(low < high && nums[high] == nums[high - 1]) --high;
            int mid = low + ((high - low) >> 1);
            if(target == nums[mid]) return true;
            if(nums[low] < nums[mid]){
                if(nums[low] <= target && nums[mid] > target) high = mid - 1;
                else low = mid + 1;
            }else{
                if(mid + 1 < nums_size && nums[mid + 1] <= target && nums[high] >= target) low = mid + 1;
                else high = mid - 1;
            }
        }
        return target == nums[low];
    }
};
