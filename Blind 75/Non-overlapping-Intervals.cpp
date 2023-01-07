class Solution {
public:
    // TC: O(N * logN)
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
          [](const std::vector<int>& a, const std::vector<int>& b) {return a[1] < b[1];});
        
        int result = 0;
        int prevEnd = INT_MIN;
        for(int i = 0; i < intervals.size(); ++i){
            if(prevEnd > intervals[i][0]) ++result;
            else prevEnd = intervals[i][1];
        }  
        return result;
    }
};

class Solution2 {
public:
    // TC: O(N * logN)
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
          [](const std::vector<int>& a, const std::vector<int>& b) {return a[0] < b[0];});
        
        int result = 0;
        int prevEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i){
            if(prevEnd > intervals[i][0]){
                ++result;
                prevEnd = min(prevEnd, intervals[i][1]);
            }else prevEnd = intervals[i][1];
        }
                
        return result;
    }
};