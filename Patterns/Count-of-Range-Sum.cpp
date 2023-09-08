// UNDERSTAND THIS SOLUTION!!
class Solution {
public:
    // TC: O(N * logN)
    // SC: O(N)
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower;
        this->upper = upper;
        vector<long> prefixSum(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); ++i) prefixSum[i + 1] = prefixSum[i] + nums[i];
        return countRangeSumHelper(prefixSum, 0, prefixSum.size() - 1);
    }
private:
    int countRangeSumHelper(vector<long>& prefixSum, int begin, int end) {
        if(begin >= end) return 0;
        const int mid = begin + (end - begin) / 2;
        int count = countRangeSumHelper(prefixSum, begin, mid) + countRangeSumHelper(prefixSum, mid + 1, end);
        for(int leftStart = begin, lowerEnd = mid + 1, upperEnd = mid + 1; leftStart <= mid; ++leftStart) {
            while(lowerEnd <= end && prefixSum[lowerEnd] - prefixSum[leftStart] < lower) ++lowerEnd;
            while(upperEnd <= end && prefixSum[upperEnd] - prefixSum[leftStart] <= upper) ++upperEnd;
            count += upperEnd - lowerEnd;
        }
        inplace_merge(prefixSum.begin() + begin, prefixSum.begin() + mid + 1, prefixSum.begin() + end + 1);
        return count;
    }

    int lower;
    int upper;
};


class Solution2 {
public:
    // TC: O(N * (upper - lower))
    // SC: O(N)
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> prefixSum(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); ++i) prefixSum[i + 1] = prefixSum[i] + nums[i];
        
        unordered_map<long, int> prefixSumFreqs;
        int count = 0;
        for(const auto& prefix : prefixSum){
            for(int target = lower; target <= upper; ++target){
                if(auto it = prefixSumFreqs.find(prefix - target); it != prefixSumFreqs.end()) 
                    count += it->second;
            }
            ++prefixSumFreqs[prefix];
        }
        return count;
    }
};


class Solution3 {
public:
    // TC: O(N^2)
    // SC: O(N)
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> prefixSum(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); ++i){
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        int count = 0;
        for(int i = 0; i < prefixSum.size(); ++i){
            for(int j = i + 1; j < prefixSum.size(); ++j){
                long rangeSum = prefixSum[j] - prefixSum[i];
                count += rangeSum >= lower && rangeSum <= upper;
            }
        }
        return count;
    }
};
