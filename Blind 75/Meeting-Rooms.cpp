 #include <iostream>
 #include <bits/stdc++.h>               // sort()
 
 
 
 using namespace std;
 
 
 
 /*class Interval {
 public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
 };*/


/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
 
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
     // TC: O(n * logn)
    bool canAttendMeetings(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval & i1, const Interval & i2) { return i1.start < i2.start; });
        
        for(int i = 0; i < intervals.size() - 1; ++i) {
            if(intervals[i].end > intervals[i + 1].start) return false;
        }
        
        return true;
    }
};


/*void TEST1(){
    vector<Interval> input({{0, 30}, {5, 10}, {15, 20}});
    Solution solution;
    if(false == solution.canAttendMeetings(input)) cout << "SUCCESS: TEST1" << endl;
    else cerr << "FAIL: TEST1" << endl;
}

void TEST2(){
    vector<Interval> input({{5, 8}, {9, 15}});
    Solution solution;
    if(true == solution.canAttendMeetings(input)) cout << "SUCCESS: TEST2" << endl;
    else cerr << "FAIL: TEST2" << endl;
}

void TEST3(){
    vector<Interval> input({{8, 10}, {0, 8}});
    Solution solution;
    if(true == solution.canAttendMeetings(input)) cout << "SUCCESS: TEST3" << endl;
    else cerr << "FAIL: TEST3" << endl;
}


int main() {
    TEST1();
    TEST2();
    TEST3();

    return 0;
}*/