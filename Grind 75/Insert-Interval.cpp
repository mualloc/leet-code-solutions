#define START(x) (x[0])
#define END(x) (x[1])

class Solution {
public:
    /*vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {        
        int i = 0;
        vector<vector<int>> result;
        
        while(i < intervals.size() && END(intervals[i]) < START(newInterval)){
            result.push_back(intervals[i++]);
        }
        while(i < intervals.size() && END(newInterval) >= START(intervals[i])){
            START(newInterval) = min(START(intervals[i]), START(newInterval));
            END(newInterval) = max(END(intervals[i]), END(newInterval));
            i++;
        }
        result.push_back(newInterval);
        while(i < intervals.size()){
             result.push_back(intervals[i++]);
        }

        return result;
    }*/
    
    // https://www.youtube.com/watch?v=A8NUOmlwOlM
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;     
        for(size_t i = 0; i < intervals.size(); i++){
            vector<int> & interval = intervals[i];
            if(newInterval[1] < interval[0]){
                result.push_back(newInterval);
                while(i < intervals.size()){
                    result.push_back(intervals[i++]);
                }
                return result;
            }else if(newInterval[0] > interval[1]){
                result.push_back(interval);
            }else{
                newInterval[0] = std::min(newInterval[0], interval[0]);
                newInterval[1] = std::max(newInterval[1], interval[1]);
            }
        }
        result.push_back(newInterval);
        return result;
    }
};