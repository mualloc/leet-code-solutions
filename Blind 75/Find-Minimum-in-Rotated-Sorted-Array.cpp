class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high && nums[low] > nums[high]){
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[high]) low = mid + 1;
            else high = mid;
        }
        return nums[low];
    }
};


// NOTE: BU COZUMU PEK ANLAMADIM!!
class Solution2 {
public:
    int findMin(vector<int>& nums) {
        int result = nums[0];
        int low = 1, high = nums.size() - 1;
        while(low <= high){
            if(nums[low] < nums[high]){
                result = min(result, nums[low]);
                break;
            }
            int mid = low + (high - low) / 2;
            result = min(result, nums[mid]);
            if(nums[mid] < nums[low]) high = mid - 1;
            else low = mid + 1;
        }
        return result;
    }
};


// 0 1 2 3 4 5 6 7 8 9
// 1 2 3 4 5 6 7 8 9 0
// 9 0 1 2 3 4 5 6 7 8 