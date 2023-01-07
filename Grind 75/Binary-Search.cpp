// NOTE: Very good explanation (lower/upper mid): https://leetcode.com/problems/binary-search/discuss/423162/Binary-Search-101

class Solution {
  public:
    /*int search(vector<int>& nums, int target) {
        int startIndex = 0;
        int endIndex = nums.size() - 1;

        while(startIndex <= endIndex){
            size_t midIndex = startIndex + (endIndex - startIndex) / 2;
            if(target == nums[midIndex]){
                return midIndex;
            }else if(target < nums[midIndex]){
                endIndex =  midIndex - 1;
            }else{
                startIndex = midIndex + 1;
            }
        }
        return -1;
    }*/
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        // NOTE: 2 versiyon arasındaki farkı iyi ANLA!!
        while(low < high){
            // Version 1
            /*int mid = low + (high - low + 1) / 2;
            if(target < nums[mid]){
                high = mid - 1;
            }else{
                low = mid;
            }*/
            // Version 2
            int mid = low + (high - low) / 2;
            if(target > nums[mid]){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        
        return nums[/*low*/high] == target ? /*low*/high : -1;
    }


    // Recursive
    /*int search(vector < int > & nums, int target) {
      return binarySearch(nums, target, 0, nums.size() - 1);
    }

    int binarySearch(vector < int > & nums, int target, int start, int end) {
      if (start <= end) {
        int midIndex = start + (end - start) / 2;
        if (target == nums[midIndex]) {
          return midIndex;
        } else if (target < nums[midIndex]) {
          return binarySearch(nums, target, start, midIndex - 1);
        } else {
          return binarySearch(nums, target, midIndex + 1, end);
        }
      } else {
        return -1;
      }
    }*/
};