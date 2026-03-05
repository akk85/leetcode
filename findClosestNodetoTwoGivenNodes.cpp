#include "common.hpp"

/*
You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

You are also given two integers node1 and node2.

Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

intution:
    Note that edges may contain cycles.
    Compute distances from node1.
    Compute distances from node2.
    For each node reachable by both, evaluate
    max(dist1[i], dist2[i]).
    Choose the node that minimizes this value.
*/

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> distanceNode1 = getNodeDistances(edges, node1);
        vector<int> distanceNode2 = getNodeDistances(edges, node2);

        int bestDistance = INT_MAX;
        int bestNode = -1;
        for (int node = 0; node < n; node ++){
            if (distanceNode1[node] == -1 || distanceNode2[node] == -1) {
                continue;
            }

            int currdistance = max(distanceNode1[node], distanceNode2[node]);

            if (currdistance < bestDistance){
                bestDistance = currdistance;
                bestNode = node;
            }
        }
        return bestNode;
    }

    vector<int> getNodeDistances(vector<int>& edges, int startNode){
        int n = edges.size();
        vector<int> distance(n, -1);

        int current = startNode;
        int dist = 0;

        while(current != -1 && distance[current] == -1){
            distance[current] = dist;
            current = edges[current];
            dist ++;
        }

        return distance;
    }
};

int main(){
    Solution sol;
    
    vector<int> edges = {2,2,3,-1};
    int node1 = 0, node2 = 1;

    cout << sol.closestMeetingNode(edges, node1, node2) << endl; // 2

    edges = {1,2,-1};
    node1 = 0, node2 = 2;

    cout << sol.closestMeetingNode(edges, node1, node2) << endl; // 2

    edges = {4,3,0,5,3,-1};
    node1 = 4, node2 = 0;

    cout << sol.closestMeetingNode(edges, node1, node2) << endl; // 4

    edges = {4,4,4,5,1,2,2};
    node1 = 1, node2 = 1;

    cout << sol.closestMeetingNode(edges, node1, node2) << endl; // 1

    edges = {9,8,7,0,5,6,1,3,2,2};
    node1 = 1, node2 = 6;

    cout << sol.closestMeetingNode(edges, node1, node2) << endl; // 1
}