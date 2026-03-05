#include "common.hpp"

/*
You are given a network of n directed nodes, labeled from 1 to n. 

You are also given times, a list of directed edges where times[i] = (ui, vi, ti).

ui is the source node (an integer from 1 to n)
vi is the target node (an integer from 1 to n)
ti is the time it takes for a signal to travel from the source to the target node (an integer greater than or equal to 0).
You are also given an integer k, representing the node that we will send a signal from.

Return the minimum time it takes for all of the n nodes to receive the signal. 

If it is impossible for all the nodes to receive the signal, return -1 instead.
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int startNode = k;

        vector<vector<pair<int, int>>> adjlist(n + 1);
        for (const vector<int>& edge : times){
            int source = edge[0], dst = edge[1], time = edge[2];
            adjlist[source].push_back({dst, time});
        }
        vector<int> nodeTimes(n + 1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, startNode});

        while(!minHeap.empty()){
            auto [time, node] = minHeap.top(); minHeap.pop();
            
            if (nodeTimes[node] != INT_MAX){
                continue;
            }
            
            nodeTimes[node] = time;

            for (const auto& [neighNode, neighTime] : adjlist[node]){
                
                if (nodeTimes[neighNode] == INT_MAX){
                    minHeap.push({time + neighTime, neighNode});
                }
            }

        }

        int maxTime = INT_MIN;
        for (int i = 1; i <= n; i++){
            if (nodeTimes[i] == INT_MAX){
                return -1;
            }
            maxTime = max(maxTime, nodeTimes[i]);
        }

        return maxTime;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> times = {{1,2,1},{2,3,1},{1,4,4},{3,4,1}};

    cout << sol.networkDelayTime(times, 4, 1) << endl; // 3

    times = {{1,2,1},{2,3,1}};

    cout << sol.networkDelayTime(times, 3, 2) << endl; // -1
}