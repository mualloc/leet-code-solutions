class Solution {
public:
    // NOTE: Another interesting solution: https://leetcode.com/problems/merge-intervals/discuss/21223/Beat-98-Java.-Sort-start-and-end-respectively.
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), sortByStart/*[](const auto &v1, const auto &v2){ return v1[0] < v2[0]; }*/);      
        result.push_back(intervals[0]);
        for(size_t i = 1; i < intervals.size(); i++){
            vector<int> & interval = intervals[i];
            if(result.back()[1] < interval[0]){
                result.push_back(interval);
            }else{
                result.back()[1] = max(result.back()[1],interval[1]);
            }
        }      
        return result;
    }
    
private:
    static bool sortByStart(const vector<int> &v1, const vector<int> &v2){
        return v1[0] < v2[0];
    }
};