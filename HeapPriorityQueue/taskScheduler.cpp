#include "../common.hpp"

/*
You are given an array of CPU tasks tasks, where tasks[i] is an uppercase english character from A to Z. 

You are also given an integer n.

Each CPU cycle allows the completion of a single task, and tasks may be completed in any order.

The only constraint is that identical tasks must be separated by at least n CPU cycles, to cooldown the CPU.

Return the minimum number of CPU cycles required to complete all tasks.

Thought process:
    1. Use a maxHeap to execute tasks according to their frequencies 
    2. Use a queuu to handle tasks and their idle time
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> counter;
        for (const char& task : tasks) {
            counter[task]++;
        }

        priority_queue<pair<int, char>>  maxHeap; // {freq, task}
        queue<pair<pair<int, char>, int>> queue;  // {freq, task},  time it can be put back into heap for processing
        for (const auto& [task, freq] : counter){
            maxHeap.push({freq, task});
        }

        int time = 0;
        while(!maxHeap.empty() || !queue.empty()){
            time += 1;

            // remove from heap
            if (!maxHeap.empty()){
                auto [freq, currTask] = maxHeap.top(); maxHeap.pop();

                if (freq - 1 > 0) queue.push({{freq - 1, currTask}, time + n + 1});
            }

            // push to queue 
            if (!queue.empty() && queue.front().second == time){
                auto [freq, task] = queue.front().first;

                queue.pop();
                maxHeap.push({freq, task});
            }
        }

        return time;
    }
};

int main(){
    Solution sol;

    vector<char> tasks = {'A','A','A','B','B','C','C'};

    cout << sol.leastInterval(tasks, 1) << endl;

}