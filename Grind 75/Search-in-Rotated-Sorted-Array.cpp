class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
      
        // Note that one portion divided by mid index is definitely sorted.
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(target == nums[mid]) return mid;
            if(nums[mid] < nums[high]){             // If right portion is sorted
                if(isInRange(nums[mid], nums[high], target)){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }else{                  // If left portion is sorted
                if(isInRange(nums[low], nums[mid], target)){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }   
            }
        }                                  
        return -1;
    }
    
    bool isInRange(int low, int high, int target){
        return target >= low && target <= high;
    }
};