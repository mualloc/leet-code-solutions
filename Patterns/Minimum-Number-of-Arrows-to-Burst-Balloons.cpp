// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/solutions/3000334/python3-greedy-approach-explained/
class Solution {
public:
    // TC: O(N*logN)
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& v1, const auto& v2) { return v1[1] < v2[1]; });
        int result = 1;
        int arrow = points[0][1];
        for(int i = 1; i < points.size(); ++i) {
            if(points[i][0] > arrow) {
                arrow = points[i][1];
                ++result;
            }
        }
        return result;
    }
};

class Solution2 {
public:    
    // TC: O(N*logN)
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        reverse(points.begin(), points.end());
        int result = 1;
        int arrow = points[0][0];
        for(int i = 1; i < points.size(); ++i){
            if(points[i][1] < arrow) {
                arrow = points[i][0];
                ++result;
            }
        }
        return result;
    }
};
