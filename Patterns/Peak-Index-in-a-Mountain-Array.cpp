class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while(low < high){
            int mid = low + ((high - low) >> 1);
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
            if(arr[mid] > arr[mid - 1]) low = mid;
            else high = mid;
        }
        return -1;    
    }
};

class Solution2 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while(low < high){
            int mid = low + ((high - low) >> 1);
            if(arr[mid] < arr[mid + 1]) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};
