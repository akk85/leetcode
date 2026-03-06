#include "../common.hpp"

/*
Given an array of meeting time interval objects consisting of start and end times [[start_1,end_1],[start_2,end_2],...] (start_i < end_i), determine if a person could add all meetings to their schedule without any conflicts.

Note: (0,8),(8,10) is not considered a conflict at 8

thouht process:
    sort all meetings by theie start times and ietrate over them checking a meetings end time is not greater 
    than seconds meeting start time 
*/

class Interval{
public:
    int start;
    int end;
    Interval(int startTime, int endTime) : start(startTime), end(endTime) {}; 
};

bool compareIntervals(const Interval& a, Interval& b){
    return a.start < b.start;   // sort by start time ascending
}
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compareIntervals);

        int n = intervals.size();
        for (int i = 0; i < n; i++){
            Interval prev = intervals[i - 1];
            Interval curr = intervals[i];

            if (prev.end > curr.start){
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<Interval> intervals = { Interval(0, 8), Interval(8, 10) };
    
    cout << boolalpha << sol.canAttendMeetings(intervals) << endl; // Output: true

    intervals = { Interval(0, 8), Interval(7, 10) };
    cout << boolalpha << sol.canAttendMeetings(intervals) << endl; // Output: false
}