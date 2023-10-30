class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int index1{0}, index2{0};
        while(index1 < firstList.size() && index2 < secondList.size()) {
            const auto &first{firstList[index1]}, &second{secondList[index2]};
            if(first[0] <= second[1] && second[0] <= first[1]) result.push_back({max(first[0], second[0]), min(first[1], second[1])});
            first[1] > second[1] ? ++index2 : ++index1;
        }
        return result;
    }
};
