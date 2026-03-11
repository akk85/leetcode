#include "../common.hpp"

/*
We have n cities labeled from 1 to n. 
Two different cities with labels x and y are directly connected by a bidirectional road if and only if x and y share a common divisor strictly greater 
than some threshold. More formally, cities with labels x and y have a road between them if there exists an integer z such that all of the following are true:

x % z == 0,
y % z == 0, and
z > threshold.
Given the two integers, n and threshold, and an array of queries, you must determine for each queries[i] = [ai, bi] if cities ai and bi are 
connected directly or indirectly. (i.e. there is some path between them).

Return an array answer, where answer.length == queries.length and answer[i] is true if for the ith query, 
there is a path between ai and bi, or answer[i] is false if there is no path.
*/

using vec = vector<int>;
class Solution {
private:
    vec parent;
    vec size;
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
    }
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int node = 1; node <= n; node ++){
            parent[node] = node;
            size[node]   = 1;
        }

        for (int node = threshold + 1; node <= n; node ++){
            for (int i = 2; i * node <= n; i ++){
                int divisor = i * node;
                Union(node, divisor);
            }
        }

        vector<bool> result;
        for (const vec& query : queries){
            int node1 = query[0], node2 = query[1];
            bool hasPath = Find(node1) == Find(node2);
            result.push_back(hasPath);
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

    int n = 6, threshold = 2;
    vector<vector<int>> queries = {{1,4}, {2,5}, {3,6}};
    vector<bool> result = sol.areConnected(n, threshold, queries); // [false,false,true]
    printVector(result);


    n = 6, threshold = 0;
    queries = {{4,5},{3,4},{3,2},{2,6},{1,3}};
    result = sol.areConnected(n, threshold, queries); // [true,true,true,true,true]
    printVector(result);

    n = 5, threshold = 1;
    queries = {{4,5},{4,5},{3,2},{2,3},{3,4}};
    result = sol.areConnected(n, threshold, queries); // [false,false,false,false,false]
    printVector(result);
}

