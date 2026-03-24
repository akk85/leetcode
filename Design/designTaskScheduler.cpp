#include "../common.hpp"

/*
You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. 

Each CPU interval can be idle or allow the completion of one task. 

Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskFreqMap;
        for (const char& task : tasks){
            taskFreqMap[task] += 1;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (const auto& [task, freq] : taskFreqMap){
            maxHeap.push({freq, task});
        }

        queue<tuple<char, int, int>> coolDownQueue;  // task, count, releaseTime

        int interval;
        int time = 0;
        while(!maxHeap.empty() || !coolDownQueue.empty()){
            if (!coolDownQueue.empty() && std::get<2>(coolDownQueue.front()) <= time){
                auto [task, count, releaseTime] = coolDownQueue.front(); coolDownQueue.pop();
                maxHeap.push({count, task});
            }

            if (!maxHeap.empty()){
                auto [count, task] = maxHeap.top(); maxHeap.pop();
                count -= 1;
                if (count > 0){
                    coolDownQueue.push({task, count, time + n + 1});
                }
            } 
            interval += 1;
            time += 1;
        }

        return interval;
    }
};

