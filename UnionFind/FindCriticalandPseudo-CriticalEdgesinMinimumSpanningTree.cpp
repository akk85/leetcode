#include "../common.hpp"

/*
Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] 
represents a bidirectional and weighted edge between nodes ai and bi. 
A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.

Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). 
An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. 
On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

Note that you can return the indices of the edges in any order.
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

        // make each node its own parent
        for (int node = 0; node < n; node ++){
            parent[node] = node;
            size[node]   = 1;
        }
    }
    int Find(int node){
        while(node != parent[node]){
            parent[node] = parent[parent[node]]; //path comprehension
            node = parent[node];
        }
        return node;
    }
    bool Union(int node1, int node2){
        int root1 = Find(node1), root2 = Find(node2);
        if (root1 == root2){
            return true;  // already connected 
        }
        else if (size[root1] > size[root2]){
            parent[root2] = root1;
            size[root1]  += size[root2];
        } 
        else {
            parent[root1] = root2;
            size[root2]  += size[root1];
        }
        return false;
    }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vec critical;
        vec pseudoCritical;
        vector<vec> sortedEdges;
        int size = edges.size();
        for (int i = 0; i < size; i++){
            int node1  = edges[i][0];
            int node2  = edges[i][1];
            int weight = edges[i][2];
            sortedEdges.push_back({weight, node1, node2, i}); // weight, node1, node2, index
        }

        sort(sortedEdges.begin(), sortedEdges.end());

        // Step 1: Find Optimal Base MST 
        int MSTBaseCost = 0;
        UnionFind unionFind(n);
        for (const auto& edge : sortedEdges){    
            int weight = edge[0], node1 = edge[1], node2 = edge[2];
            bool alreadyConnected = unionFind.Union(node1, node2);
            if (alreadyConnected){
                continue;
            }
            MSTBaseCost += weight;
        }

        // Step 2: Find critical edges:: edge is critical if mst cannot be formed or formed but with much higher cost than optimal mst 
        for (const auto& edge : sortedEdges){
            UnionFind unionFind(n);
            int MSTCriticalCost = 0;
            int edgeCount = 0;     bool isCritical = false;
            for (const auto& edge2 : sortedEdges){
                if (edge == edge2){      // skip this edge 
                    continue;
                }
                int weight = edge2[0], node1 = edge2[1], node2 = edge2[2];
                bool alreadyConnected = unionFind.Union(node1, node2);

                if (alreadyConnected){
                    continue;
                }
                edgeCount += 1;
                MSTCriticalCost += weight; 
            }
            if (edgeCount != n - 1 || MSTCriticalCost > MSTBaseCost){
                isCritical = true;
                critical.push_back(edge[3]); //index 
            }

            if (isCritical){
                continue;
            }

            // Step 3: Find pseudocritical edges:: edge is pseudocritical if its not critical but appears in other mst's 
            UnionFind unionFind2(n);
            int MSTPseudoCriticalCost = 0;
            unionFind2.Union(edge[1], edge[2]);
            MSTPseudoCriticalCost += edge[0];

            for (const auto& edge2 : sortedEdges){
                if (edge == edge2){      // skip this edge since we already forced it before 
                    continue;
                }
                int weight = edge2[0], node1 = edge2[1], node2 = edge2[2];
                bool alreadyConnected = unionFind2.Union(node1, node2);

                if (alreadyConnected){
                    continue;
                }
                MSTPseudoCriticalCost += weight; 
            }

            if (MSTPseudoCriticalCost == MSTBaseCost){
                pseudoCritical.push_back(edge[3]); 
            }
        }

        vector<vec> result;
        result.push_back(critical);
        result.push_back(pseudoCritical);

        return result;
    }
};

void printVector(vector<vector<int>>& result){
    for (const vector<int>& vec : result){
        for (const int& val : vec){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main(){
    Solution sol;

    int n = 5;
    vector<vector<int>> edges = {{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}};

    vector<vector<int>> result = sol.findCriticalAndPseudoCriticalEdges(n, edges);

    printVector(result);   // [[0,1],[2,3,4,5]]
}