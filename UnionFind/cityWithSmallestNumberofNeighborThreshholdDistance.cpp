#include "../common.hpp"

/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a 
bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, 
If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
*/

using vec = vector<int>;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<pair<int, int>>> adjList(n);
        for (const vector<int>& edge : edges){
            int node1 = edge[0], node2 = edge[1], weight = edge[2];

            adjList[node1].push_back({node2, weight});
            adjList[node2].push_back({node1, weight});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        vec reachableCities(n);
        for (int node = 0; node < n; node ++){
            vector<int> distance(n, INT_MAX);
            minHeap.push({0, node});
            distance[node] = 0;

            while(!minHeap.empty()){
                auto [weight, city] = minHeap.top(); minHeap.pop();

                for (const auto& [neighbor, neighborDistance] : adjList[city]){
                    if (weight + neighborDistance < distance[neighbor]){
                        distance[neighbor] = weight + neighborDistance;
                        minHeap.push({weight + neighborDistance, neighbor});
                    }
                }
            }

            int count = 0;
            for (int city = 0; city < n; city ++){
                int dist = distance[city];

                if (dist <= distanceThreshold){
                    count ++;
                }
            }

            reachableCities[node] = count;
        }

        // find smallest reachable cities
        int city = 0;
        for (int node = 1; node < n; node ++){
            int cities = reachableCities[node];

            if (cities < reachableCities[city] || (cities == reachableCities[city] && node > city)){
                city = node;
            }
        }

        return city;
    }
};

int main(){
    Solution sol;

    int n = 4;
    int distanceThreshold = 4;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};

    cout << sol.findTheCity(n, edges, distanceThreshold) << endl; // 3
}