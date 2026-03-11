#include "../common.hpp"

/*
You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1.

You are also given an integer array nums of length n sorted in non-decreasing order, and an integer maxDiff.

An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).

You are also given a 2D integer array queries. For each queries[i] = [ui, vi], determine whether there exists a path between nodes ui and vi.

Return a boolean array answer, where answer[i] is true if there exists a path between ui and vi in the ith query and false otherwise.

Thouthg process:
    Since nodes are sorted need only to check adjacent nodes.
    If abd diff of nums[i] - nums[i+1] <= maxDiff we union them.
    if this fails no need to union neighbors since no other node can bridge that gap as they are sorted in increasing order.
    The transitive chaining thrugh adjacent nodes will handle all indirect connections automatically 

    Time is O(n) to build and 0(α(n)) for each query ->  inverse Ackermann function which with path compression boils down to constant time(0(1))
    Space is O(n)
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // self union each node
        parent.resize(n);
        size.resize(n);
        for (int node = 0; node < n; node ++){
            parent[node] = node;
            size[node]   = 1;
        }

        // union node and adjacent neighbor
        for (int node = 0; node < n - 1; node ++){
            int diff = abs(nums[node] - nums[node + 1]);
            if (diff <= maxDiff){
                Union(node, node + 1);
            }
        }

        // check for queries
        vector<bool> result;
        for (const vec& query : queries){
            int node1 = query[0], node2 = query[1];
            result.push_back(Find(node1) == Find(node2));
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

    int n = 4, maxDiff = 2;
    vector<int> nums = {2,5,6,8};
    vector<vector<int>> queries = {{0,1},{0,2},{1,3},{2,3}};

    vector<bool> result = sol.pathExistenceQueries(n, nums, maxDiff, queries); // false,false,true,true

    printVector(result);
}