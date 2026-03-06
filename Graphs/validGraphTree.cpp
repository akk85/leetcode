#include "../common.hpp"

class Solution{
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (static_cast<int>(edges.size()) != n - 1){
            return false;
        }
        vector<vector<int>> adjList(n);
        for (const vector<int>& edge : edges){
            int node1 = edge[0];
            int node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }   
        vector<int> visited(n, false);
        queue<pair<int, int>> q;
        q.push({-1, 0});  //parent and first node
        visited[0] = true;

        while (!q.empty()){
            auto [parent, currNode] = q.front(); q.pop();

            for (const int neighbor : adjList[currNode]){
                if (neighbor == parent){
                    continue;
                }
                if (visited[neighbor]){
                    return false;
                }
                q.push({currNode, neighbor});
                visited[neighbor] = true;
            }
        }

        for (bool v : visited){
            if (!v) return false;
        }
        return true;
        
    }
};

int main(){
    Solution sol;

    int n = 5;  vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};

    cout << boolalpha << sol.validTree(n, edges) << endl;

    n = 5; edges = {{0, 1}, {0, 2}, {2, 3}, {1, 3}, {1, 4}};

    cout << boolalpha << sol.validTree(n, edges) << endl;

    n=6;  edges = {{0, 1}, {2, 3}, {4, 5}, {3, 4}, {2, 5}};

    cout << boolalpha << sol.validTree(n, edges) << endl;
}