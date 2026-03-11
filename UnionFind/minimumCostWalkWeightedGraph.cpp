#include "../common.hpp"

/*
There is an undirected weighted graph with n vertices labeled from 0 to n - 1.

You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.

A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.

The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.

You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.

Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.

Thought process:
    since we are bitwise AND each path, to minimize cost we need to walk from each node all possible visited nodes
    in essence, for each node, minimuc AND cost is AND all paths in this component
    since AND operation always promises to either keep value as it is or reduce it eg
    7 and 7 = 7
    7 & 5 = 5
    6 & 5 = 4 so performing and on all paths in compoennt minimized the cost to walk from any node
*/
using vec = vector<int>;
class UnionFind{
private:
    vec parent;
    vec size;
public:
    UnionFind(int n){
        parent.resize(n);
        size.resize(n);

        for (int node = 0; node < n; node ++){
            parent[node] = node;
            size[node]   = 1;
        }
    }
    int Find(int node){
        while(node != parent[node]){
            parent[node] = parent[parent[node]]; // path compression
            node = parent[node];
        }
        return node;
    }
    void Union(int node1, int node2){
        int root1 = Find(node1), root2 = Find(node2);

        if (root1 == root2){
            return; // already connected
        } 
        else if (size[root1] >= size[root2]){
            parent[root2] = root1;
            size[root1]  += size[root2];
        }
        else {
            parent[root1] = root2;
            size[root2]  += size[root1];
        }
        return;
    }
};
class Solution {
private:
    unordered_map<int, int> rootCostMap;
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        UnionFind uf(n);

        // union all edges
        for (const vector<int>& edge : edges){
            int node1 = edge[0], node2 = edge[1], weight = edge[2];

            uf.Union(node1, node2);
        }

        // calculate cost for each root
        for (const vector<int>& edge : edges){
            int node1 = edge[0], node2 = edge[1], weight = edge[2];
            int root = uf.Find(node1);

            if (!rootCostMap.contains(root)){
                rootCostMap[root] = weight;
            } else {
                rootCostMap[root] &= weight;
            }
        }

        // queries
        vector<int> ans;
        for (const vector<int>& q: query){
            int node1 = q[0], node2 = q[1];

            if (node1 == node2){  // same node cost == 0
                ans.push_back(0);
                continue;
            }

            int root1 = uf.Find(node1), root2 = uf.Find(node2);

            if (root1 != root2){
                ans.push_back(-1);
            }
            else {
                int cost = rootCostMap[root1];
                ans.push_back(cost);
            }
        }

        return ans;

    }
};

void printResult(const vector<int>& result){
    for (const int& val : result){
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    Solution sol;

    int n = 5;
    vector<vector<int>> edges = {{0,1,7},{1,3,7},{1,2,1}};
    vector<vector<int>> query = {{0,3},{3,4}};

    vector<int> result = sol.minimumCost(n, edges, query);

    printResult(result); // 1, -1
    return 0;
}