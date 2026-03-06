#include "../common.hpp"

/*
You are given n tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] means that the ith task will be available to process at enqueueTime[i] and will take processingTime[i] to finish processing.

You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

If the CPU is idle and there are no available tasks to process, the CPU remains idle.

If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. 

If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.

Once a task is started to process, the CPU will process the entire task without stopping.

The CPU can finish a task then start a new one instantly.


Return the order in which the CPU will process the tasks.
*/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>>  sortedTasks;   //[processingtime, duration, index]
        int index = 0;
        for (const vector<int>& task : tasks){
            sortedTasks.push_back({task[0], task[1], index});
            index ++;
        }

        sort(sortedTasks.begin(), sortedTasks.end());

        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        int taskPointer = 0;
        int currTime = 0;
        vector<int> result;
        while(taskPointer < n || !minHeap.empty()){

            // push to queue
            while(taskPointer < n && sortedTasks[taskPointer][0] <= currTime){
                int duration = sortedTasks[taskPointer][1];
                int index    = sortedTasks[taskPointer][2];
                minHeap.push({duration, index});       // length, index
                taskPointer ++;
            }

            if (minHeap.empty()){
                currTime = sortedTasks[taskPointer][0];
            }

            else {
                // process top task
                auto [duration, index] = minHeap.top(); minHeap.pop();
                result.push_back(index);

                currTime += duration;
            }
        }
        return result;
    }
};

void printResult(vector<int>& result){
    for (const int& val : result){
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    Solution sol;

    vector<vector<int>> tasks = {{1, 4}, {3, 3},{2, 1}};   // [0,2,1]

    vector<int> result = sol.getOrder(tasks);

    printResult(result);

    tasks = {{5, 2}, {4, 4},{4, 1}, {2, 1}, {3, 3}};  //  [3,4,2,0,1]

    result = sol.getOrder(tasks);

    printResult(result);
}