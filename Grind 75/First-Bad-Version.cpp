// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        
        while(low < high){
            int mid = low + (high - low) / 2;
            if(isBadVersion(mid)){
                high = mid;
                //if(1 == mid) return mid;
                //if(mid > 1 && false == isBadVersion(mid - 1)) return mid;
            }else{
               low = mid+1; 
            }
        }
        return /*high*/low;
    }
};