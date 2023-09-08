// https://www.lintcode.com/problem/850/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;


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
class Interval {
 public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
    bool operator == (const Interval &i) const {
        return i.start == start && i.end == end;
    }
};


class Solution {
public:
    /**
     * @param schedule: a list schedule of employees
     * @return: Return a list of finite intervals 
     */
    vector<Interval> employeeFreeTime(const vector<vector<int>> &schedule) {
        vector<Interval> slots;
        for(const auto& intervals : schedule){
            for(int i = 0; i < intervals.size(); i += 2) {
                slots.push_back(Interval{intervals[i], intervals[i + 1]});
            }
        }

        sort(slots.begin(), slots.end(), [] (const auto& i1, const auto& i2) {return i1.start < i2.start;});
        
        vector<Interval> result;
        int prevEnd = slots[0].end;
        for(const auto& slot : slots){
            if(slot.start > prevEnd) result.emplace_back(prevEnd, slot.start);
            prevEnd = max(prevEnd, slot.end);
        }
        return result;
    }
};


int main()
{
    Solution s;
    int test_index = 1;
    if(s.employeeFreeTime({{1,2,5,6}, {1,3}, {4,10}}) == vector<Interval>{{3,4}}) cout << "SUCCESS" << test_index++ << endl;
    else cerr << "FAIL" << test_index++ << endl;
    if(s.employeeFreeTime({{1,3,6,7}, {2,4}, {2,5,9,12}}) == vector<Interval>{{5,6}, {7,9}}) cout << "SUCCESS" << test_index++ << endl;
    else cerr << "FAIL" << test_index++ << endl;
    if(s.employeeFreeTime({{5,10}}) == vector<Interval>{}) cout << "SUCCESS" << test_index++ << endl;
    else cerr << "FAIL" << test_index++ << endl;
    if(s.employeeFreeTime({{5,7}, {7,9}}) == vector<Interval>{}) cout << "SUCCESS" << test_index++ << endl;
    else cerr << "FAIL" << test_index++ << endl; 
    
    return 0;
}
