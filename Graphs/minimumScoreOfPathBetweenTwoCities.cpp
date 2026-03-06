#include "../common.hpp"

/*
You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Thought Process:
    starting from city 1, visit all neighbors and keep track of min distance btwn each node neighbors
    Mark nodes as visited when we pop node from the queue and visit all of its neighbors 
    return min distance 
*/
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjList(n + 1);

        for (const vector<int>& road : roads){
            int city1 = road[0], city2 = road[1], distance = road[2];
            adjList[city1].push_back({city2, distance});
            adjList[city2].push_back({city1, distance});
        }

        queue<int> q;
        q.push(1);

        vector<bool> visited(n + 1, false);
        
        int minDistance = INT_MAX;
        while(!q.empty()){
            int city = q.front(); q.pop();
            visited[city] = true;

            for (const auto& [neighborCity, distance] : adjList[city]){
                if (!visited[neighborCity]){
                    minDistance = min(minDistance, distance);
                    q.push(neighborCity);
                }
            }
        }

        return minDistance;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> roads = {
        {1,2,2},
        {1,3,4},
        {3,4,7}
    };

    cout << sol.minScore(4, roads) << endl; // 2

    roads = {
        {1,2,9},
        {2,3,6},
        {2,4,5},
        {1,4,7}
    };

    cout << sol.minScore(4, roads) << endl; // 5
}