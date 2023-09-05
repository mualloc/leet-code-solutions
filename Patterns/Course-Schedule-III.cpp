// See : https://leetcode.com/problems/course-schedule-iii/solutions/255658/recursion-dp-greedy/
class Solution {
public:
    // TC: O(C * logC)
    // SC: O(C)
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto& c1, const auto& c2){return c1[1] < c2[1];});

        priority_queue<int> durationsMaxHeap; 
        int currentTotalTime = 0;
        int result = 0;
        for(const auto& course : courses){
            durationsMaxHeap.push(course[0]);
            currentTotalTime += course[0];
            if(currentTotalTime > course[1]){
                auto maxDuration = durationsMaxHeap.top(); durationsMaxHeap.pop();
                currentTotalTime -= maxDuration;
            }
        }

        return durationsMaxHeap.size();
    }
};
