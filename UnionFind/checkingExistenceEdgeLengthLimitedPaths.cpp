#include "../common.hpp"

/*
An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. 
Note that there may be multiple edges between two nodes.

Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether there is a path between pj and qj 
such that each edge on the path has a distance strictly less than limitj .

Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is a path for queries[j] is true, 
and false otherwise.

pseduco code
    for each sorted query
        build dsu with all edges with weight less than limit
        check if root of the two query nodes are same
        use a priority queue for minimum weights edges
*/

using vec = vector<int>;
class Solution {
private:    
    vec parent;
    vec size;
    int Find(int node){
        while(node != parent[node]){
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }
    void Union(int node1, int node2){
        int root1 = Find(node1), root2 = Find(node2);

        if (root1 == root2){
            return;   // already connected
        }
        else if (size[root1] >= size[root2]){
            parent[root2] = root1;
            size[root1]  += size[root2];
        }
        else {
            parent[root1] = root2;
            size[root2]  += size[root1];
        }
    }
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n); size.resize(n);
        // self looping nodes
        for (int node = 0; node < n; node ++){
            parent[node] = node;
            size[node]   = 1;
        }

        // build queries by limit 
        vector<tuple<int,int,int,int>> sortedQueries; // limit, node1, node2, index
        int nQueries = queries.size();
        for (int index = 0; index < nQueries; index ++){
            vector<int> query = queries[index];
            int node1 = query[0], node2 = query[1], limit = query[2];
            sortedQueries.push_back({limit, node1, node2, index});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        // build edges by weight
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap; // weight, node1, node2
        for (const vector<int>& edge : edgeList){
            int node1 = edge[0], node2 = edge[1], weight = edge[2];
            minHeap.push({weight, node1, node2});
        }

        vector<bool> result(nQueries);
        // iterate over queries and build dsu for edges less than limit
        for (const auto& [limit, node1, node2, index] : sortedQueries){

            while(!minHeap.empty() && get<0>(minHeap.top()) < limit){ // top edge weight is less than limit
                auto[weight, edgeNode1, edgeNode2] = minHeap.top(); minHeap.pop();

                Union(edgeNode1, edgeNode2);
            }

            bool hasPath = Find(node1) == Find(node2);
            result[index] = hasPath;
        }

        return result;
    }
};

void printVector(vector<bool>& result){
    for (const bool& val : result){
        cout << boolalpha << val << " ";
    }
    cout << endl;

}

int main(){
    Solution sol;

    int n = 3;
    vector<vector<int>> edgeList = {{0,1,2},{1,2,4},{2,0,8},{1,0,16}};
    vector<vector<int>> queries  = {{0,1,2},{0,2,5}};

    vector<bool> result = sol.distanceLimitedPathsExist(n, edgeList, queries); // false,true

    printVector(result);

    n = 5;
    edgeList = {{0,1,10},{1,2,5},{2,3,9},{3,4,13}};
    queries  = {{0,4,14},{1,4,13}};

    result = sol.distanceLimitedPathsExist(n, edgeList, queries); // true, false

    printVector(result);
}