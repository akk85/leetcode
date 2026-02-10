#include "common.hpp"

/*
Thought process:
    1. iterate over all the nodes and create an adjency list where each node is mapped to its neighbors;
    2. iterating over each node in the adjency list, we keep a visited set of each neighbor that we visit
    3. when we iterate over neighbors of a node and see that we have already visited this neighbor before 
        * we return false as this means there is an invalid edge connection btwn this neighbor that invalidates our node
    4. return true if we never visit a node twice
    also we can exit early by checking that number of edges are exactly nodes - 1 for a valid tree

*/

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (static_cast<int>(edges.size()) != n - 1){
            return false;
        }
        // 1. Build adjecency list 
        vector<vector<int>> adjList(n);
        for (const vector<int>& edge : edges){
            int node1 = edge[0];
            int node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
/*
[[0, 1], [0, 2], [0, 3], [1, 4]]
0-> 1, 2, 3
1-> 0, 4
2-> 0
3-> 0 
4-> 1

visited = (0, 1, 2, 3, 4) 
queue =   

node   = 4
parent = 1 

neighbors = 1
neighbor = 1
*/
        // 2. bfs checking neighbors 
        unordered_set<int> visited;
        queue<pair<int, int>> q; // node, parent
        int firstNode =  0;
        int parent    = -1;
        q.push({firstNode, parent});
        visited.insert(firstNode);

        while(!q.empty()){
            auto [node, parent] =  q.front(); q.pop();

            // 3. go through all neoghbors checking if we have visited this neighbor before via some other node
            for (const int& neighbor : adjList[node]){

                if (neighbor == parent){
                    continue;      // skip parent we just came from
                }
                if (visited.contains(neighbor)){
                    return false;  // cycle detected
                }

                q.push({neighbor, node});
                visited.insert(neighbor); 
            }
        }

        return static_cast<int>(visited.size()) == n;   // all nodes must be visited for valid tree! edge list parameter might be different components 
    }
};

int main(){
    Solution sol;

    int n = 5;  vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};

    cout << boolalpha << sol.validTree(n, edges) << endl;   // true

    n = 5; edges = {{0, 1}, {0, 2}, {2, 3}, {1, 3}, {1, 4}};

    cout << boolalpha << sol.validTree(n, edges) << endl;    // false 
 
    n=6;  edges = {{0, 1}, {2, 3}, {4, 5}, {3, 4}, {2, 5}};  // false 

    cout << boolalpha << sol.validTree(n, edges) << endl;
}


