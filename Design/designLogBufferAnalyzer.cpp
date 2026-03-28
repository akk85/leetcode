#include "../common.hpp"

/*
You have a circular buffer that holds at most n logs. Logs arrive one by one, each with:

A timestamp (in ms)
A tag (like "error", "warning")

When a new log arrives, two things happen:
1. Transmission check:
    Look at all logs currently in the buffer that share the same tag as the incoming log. 
    If their timestamp falls within [newTimestamp - transmissionWindow, newTimestamp], transmit them. 
    Count those transmissions.
2.Buffer management:
    Add the new log to the buffer
    If buffer is full (exceeds capacity), remove the oldest log to make space

What you return:
    Total number of logs transmitted across the entire process.

Example Code.
    capacity = 3, transmissionWindow = 2000ms
    Logs: (1000,"error"), (2000,"warning"), (3000,"error"), (4001,"warning")

    log1 -> 1000, error
    log2 -> 2000, warning
    log3 -> 3000, error 
    log4 -> 4001, warning 
*/

class LogBurfer{
private:
    unordered_map<string , vector<int>> tagLogsmap; // tag -> vec of logs 
    queue<pair<int, string>> q;                     // log, tag
public:
    long getTotalLogsTransmitted(vector<int>& logTimeStamp, vector<string>& logTags, int bufferCacpacity, int transmissionWindow){

        int totalTransmitted = 0;
        int n = logTimeStamp.size();
        for (int index = 0; index < n; index++){
            // 1. get valid logs under same tag
            int timeStamp  = logTimeStamp[index];
            string tag     = logTags[index];
            
            int validLogs   = getLogs(tag, timeStamp, transmissionWindow);
            totalTransmitted += validLogs;

            // 2. push log to queue
            q.push({timeStamp, tag});
            tagLogsmap[tag].push_back(timeStamp);

            // 3. if over capacity remove oldest
            if (static_cast<int>(q.size()) > bufferCacpacity){
                auto [log, tag] = q.front(); q.pop();

                tagLogsmap[tag].erase(tagLogsmap[tag].begin());
            }
        }
        return totalTransmitted;
    }

    int getLogs(string& tag, int timestamp, int transmissionWindow){
        vector<int>& vec = tagLogsmap[tag];
        int windowStart = timestamp - transmissionWindow;
        int windowEnd   = timestamp;

        vector<int>::iterator left  = lower_bound(vec.begin(), vec.end(), windowStart);
        vector<int>::iterator right = upper_bound(vec.begin(), vec.end(), windowEnd);

        int count = distance(left, right);
        return count + 1;
    }
};

int main(){
    vector<int> logTimestamp = {1000,     2000,     3000,     4001};
    vector<string> logTag    = {"error", "warning", "error", "warning"};
    int bufferCapacity = 3;
    int transmissionWindow = 2000;

    LogBurfer lb;
    cout << lb.getTotalLogsTransmitted(logTimestamp, logTag, bufferCapacity, transmissionWindow) << endl; // 5
}