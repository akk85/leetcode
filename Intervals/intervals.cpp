#include <iostream>
#include <vector>
using namespace std;

class Interval{
public:
    int start;
    int end;
    Interval(int startTime, int endTime) : start(startTime), end(endTime) {};
};

// {{5,8}, {9,15}};
class Solution{
public:
    bool canAttendMeetings(vector<Interval> & intervals){

        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) {
            return x.start < y.start;
        });

        for (size_t i = 1; i < intervals.size(); i++){
            int currentStart = intervals[i].start;
            int previousEnd  = intervals[i-1].end;

            if (previousEnd > currentStart){
                return false;
            }
        }
        return true;
    }
};

/*
0 <= intervals.length <= 500
0 <= intervals[i].start < intervals[i].end <= 1,000,000
*/
int main(){
    vector<Interval> firstInterval  = {{0,8}, {8,10}};             // true
    vector<Interval> secondInterval = {{0,30}, {5,10}, {15,20}};   // false 
    vector<Interval> thirdInterval  = {{5,8}, {9,15}};             // true
    Solution s;

    cout << boolalpha << s.canAttendMeetings(firstInterval)  << endl;

    cout << boolalpha << s.canAttendMeetings(secondInterval) << endl;

    cout << boolalpha << s.canAttendMeetings(thirdInterval)  << endl;
}