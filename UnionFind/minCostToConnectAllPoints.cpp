#include "../common.hpp"

/*
You are given a 2-D integer array points, where points[i] = [xi, yi]. Each points[i] represents a distinct point on a 2-D plane.

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between the two points, i.e. |xi - xj| + |yi - yj|.

Return the minimum cost to connect all points together, such that there exists exactly one path between each pair of points.

Get the cost of each point from all other points in the list
Sort the vector to have the minimum cost of each index get connected first
if two points are already connected skip it otherwise connect it  and add cost to running total
*/

using vec  = vector<int>;
using vecT = vector<tuple<int, int, int>>;
class Solution {
private:
    vec parent;
    vec size;
    int Find(int point){
        while(point != parent[point]){
            parent[point] = parent[parent[point]];
            point = parent[point];
        }
        return point;
    }
    bool Union(int pointA, int pointB){
        int root1 = Find(pointA);
        int root2 = Find(pointB);

        if (root1 == root2){   // already in graph return true
            return true;
        }
        else if (size[root1] >= size[root2]){
            parent[root2] = root1;
            size[root1]  += size[root2];
        }
        else {
            parent[root1] = root2;
            size[root2]  += size[root1];
        }

        return false;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        size.resize(n);
        vecT edges;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                vec pointA = points[i];
                vec pointB = points[j];
                int distance = abs(pointA[0] - pointB[0]) + abs(pointA[1] - pointB[1]);
                edges.push_back({distance, i, j});
            }
        } 

        sort(edges.begin(), edges.end());

        for (int i = 0; i < n; i++){
            parent[i] = i;
            size[i]   = 1;
        }

        int totalCost = 0;
        for (const auto&[distance, pointA, pointB] : edges){
            bool alreadyConnected = Union(pointA, pointB);

            if (alreadyConnected){
                continue;
            }
            totalCost += distance;
        }

        return totalCost;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};

    cout << sol.minCostConnectPoints(points) << endl; // 20

    points = {{3,12},{-2,5},{-4,1}};

    cout << sol.minCostConnectPoints(points) << endl; // 18 
}