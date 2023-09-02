/*class Solution {
public:
    // TC: O(log(min(m, n)))
    // SC: O(1)
    // https://www.youtube.com/watch?v=q6IEA26hvXc
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) nums1.swap(nums2);  // Make nums1 shorter
        int const size = nums1.size() + nums2.size();
        const int half = size / 2;
        int left1 = 0, right1 = nums1.size() - 1;   
        while(true){
            int mid1 = left1 + ((right1 - left1) >> 1);
            int left2 = half - (mid1 + 1) - 1;
            int left1Max = nums1[mid1];
            int right1Min = mid1 + 1 < nums1.size() ? nums1[mid1 + 1] : INT_MAX;
            int left2Max = nums2[left2];
            int right2Min = left2 + 1 < nums2.size() ? nums2[left2 + 1] : INT_MAX;
            if(left1Max <= right2Min && left2Max <= right1Min){
                if(size & 1) return min(right1Min, right2Min);
                else return (max(left1Max, left2Max) + min(right1Min, right2Min)) / 2.0 ;
            }else if(left1Max > right2Min) right1 = mid1 - 1;
            else left1 = mid1 + 1;

        }
        return numeric_limits<double>::max();
    }
};*/

class Solution {
public:
    // https://leetcode.com/problems/median-of-two-sorted-arrays/solutions/2652/share-one-divide-and-conquer-o-log-m-n-method-with-clear-description/comments/378752
    // TC: O(log(mn)) = O(log(m + n))
    // SC: O(log(m + n))
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int size1 = nums1.size(), size2 = nums2.size();
        const int size = size1 + size2;
        int m1 = kthElement(nums1, 0, size1 - 1, nums2, 0, size2 - 1, (size >> 1) + 1);
        if(size & 1) return m1;
        int m2 = kthElement(nums1, 0, size1 - 1, nums2, 0, size2 - 1, (size >> 1));
        return (m1 + m2) / 2.0;
    }
private:
    // k is 1-based index.
    int kthElement(const vector<int>& nums1, int start1, int end1, const vector<int>& nums2, int start2, int end2, int k){
        if(start1 > end1) return nums2[k - start1 - 1]; // start1 points one index further which equals number of elements included from nums1  
        if(start2 > end2) return nums1[k - start2 - 1];
        int mid1 = start1 + ((end1 - start1) >> 1);
        int mid2 = start2 + ((end2 - start2) >> 1);
        if(mid1 + mid2 + 2 > k){
            if(nums1[mid1] < nums2[mid2]) return kthElement(nums1, start1, end1, nums2, start2, mid2 - 1, k);
            else return kthElement(nums1, start1, mid1 - 1, nums2, start2, end2, k);
        }else{
            if(nums1[mid1] < nums2[mid2]) return kthElement(nums1, mid1 + 1, end1, nums2, start2, end2, k);
            else return kthElement(nums1, start1, end1, nums2, mid2 + 1, end2, k);
        }
    }
};
