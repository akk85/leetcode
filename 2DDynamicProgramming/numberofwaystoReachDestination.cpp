#include "../common.hpp"


/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. 

The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between 
intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel 
from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.
*/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int lastCity = n - 1; 
        const long long MOD = 1e9 + 7;

        // build adj
        vector<vector<pair<int, int>>> adjList(n);
        for (const vector<int>& edge : roads){
            int source = edge[0], dst = edge[1], time = edge[2];
            adjList[source].push_back({dst, time});
            adjList[dst].push_back({source, time});
        }

        vector<long long> cityTime(n, INT_MAX);
        vector<long long> paths(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 0});
        cityTime[0] = 0;
        paths[0] = 1;

        while(!minHeap.empty()){
            auto [time, city] = minHeap.top(); minHeap.pop();

            if (time > cityTime[time]){
                continue;
            }

            for (const auto& [neighbor , neighTime] : adjList[city]){
                if (time + neighTime < cityTime[neighbor]){
                    cityTime[neighbor] = time + neighTime;
                    paths[neighbor] = paths[city];
                    minHeap.push({time + neighTime, neighbor});
                } 
                else if (time + neighTime == cityTime[neighbor]){
                    paths[neighbor] = (paths[neighbor] + paths[city]) % MOD;
                }
            }
        }

        return paths[lastCity] % MOD;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> roads = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5},
        {4, 6, 2}
    };

    cout << sol.countPaths(7, roads) << endl;  // 4
}