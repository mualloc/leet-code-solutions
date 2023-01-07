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
     * @return: the minimum number of conference rooms required
     */
     // TC: O(n *logn)
     // SC: O(n)
    int minMeetingRooms(vector<Interval> &intervals) {
        vector<int> startTimes, endTimes;
        for(const Interval & interval : intervals){
            startTimes.push_back(interval.start);
            endTimes.push_back(interval.end);
        }
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());
        
        int result = 0;
        for(int s = 0, e = 0, counter = 0; s < startTimes.size();  ){
            if(startTimes[s] >= endTimes[e]){
                --counter;
                ++e;
            }else{
                ++counter;
                ++s;
                result = max(result, counter);
            }
        }
        return result;
    }
};


/*void TEST1(){
    vector<Interval> input({{0, 30}, {5, 10}, {15, 20}});
    Solution solution;
    if(2 == solution.minMeetingRooms(input)) cout << "SUCCESS: TEST1" << endl;
    else cerr << "FAIL: TEST1" << endl;
}

void TEST2(){
    vector<Interval> input({{5, 8}, {9, 15}});
    Solution solution;
    if(1 == solution.minMeetingRooms(input)) cout << "SUCCESS: TEST2" << endl;
    else cerr << "FAIL: TEST2" << endl;
}

void TEST3(){
    vector<Interval> input({{8, 10}, {0, 8}});
    Solution solution;
    if(1 == solution.minMeetingRooms(input)) cout << "SUCCESS: TEST3" << endl;
    else cerr << "FAIL: TEST3" << endl;
}

void TEST4(){
    vector<Interval> input({{2, 7}});
    Solution solution;
    if(1 == solution.minMeetingRooms(input)) cout << "SUCCESS: TEST4" << endl;
    else cerr << "FAIL: TEST4" << endl;
}


int main() {
    TEST1();
    TEST2();
    TEST3();
    TEST4();

    return 0;
}*/