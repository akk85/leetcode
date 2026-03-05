#include "common.hpp"

/*
There are n cities connected by some number of flights. 
You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight 
from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 

If there is no such route, return -1.
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adjacency list
        vector<vector<pair<int, int>>> adjList(n + 1); // node -> {neighbor, cost}
        for (const vector<int>& flight : flights){
            int src = flight[0], dst = flight[1], cost = flight[2];
            adjList[src].push_back({dst, cost});
        }

        vector<int> bestStops(n, INT_MAX);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;

        minHeap.push({0,src, -1});
        bestStops[src] = -1;

        while(!minHeap.empty()){
            auto [cost, city, stops] = minHeap.top(); minHeap.pop();

            if (city == dst){
                return cost;
            }

            bestStops[city] = stops;

            for (const auto& [neighbor, neightCost] : adjList[city]){

                if (stops + 1 <= k && (bestStops[neighbor] == INT_MAX || stops + 1 < bestStops[neighbor])){
                    minHeap.push({cost + neightCost, neighbor, stops + 1});
                }
            }
        }

        return -1; // never reached here 

    }
};

int main(){
    Solution sol;

    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };

    cout << sol.findCheapestPrice(4, flights, 0, 3, 1) << endl; // 700
}