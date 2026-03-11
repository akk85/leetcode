#include "../common.hpp"

/*
You are given an array of integers nums of size n and a positive integer threshold.

There is a graph consisting of n nodes with the ith node having a value of nums[i]. 
Two nodes i and j in the graph are connected via an undirected edge if lcm(nums[i], nums[j]) <= threshold.

Return the number of connected components in this graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph 
shares an edge with a vertex outside of the subgraph.

The term lcm(a, b) denotes the least common multiple of a and b.
[2,4,8,3,9]

vec = 2 3 4 

edges = [2,4]
*/

using vec = vector<int>;
class UnionFind{
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;
public:
    UnionFind(vector<int>& nums){

        for (const int& node : nums){
            parent[node] = node;
            size[node]   = 1;
        }
    }
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
            return;
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
};
class Solution {
public:
    int countComponents(vector<int>& nums, int threshold) {
        int n = nums.size();
        
        vec nodes;
        for (int i = 0; i < n; i ++){
            int node = nums[i];
            if (node <= threshold){
                nodes.push_back(node);
            }
        }

        unordered_set<int> seen(nodes.begin(), nodes.end()); 
        UnionFind unionFind(nums);
 
        vector<vector<int>> edges;
        for (const int& node : nodes){
            for (int multiple = node*2; multiple <= threshold; multiple += node){
                if (seen.contains(multiple)){
                    int node1 = node, node2 = multiple;
                    unionFind.Union(node1, node2);
                }
            }
        }

        int count = 0;
        for (const int& node : nums){
            int nodeParent = unionFind.Find(node);

            if (node != nodeParent){    // not root for component 
                continue;
            }
            count += 1;

        }
        return count;
    }
};

int main(){
    Solution sol;

    int threshold = 5;
    vector<int> nums = {2,4,8,3,9};

    cout << sol.countComponents(nums, threshold) << endl; // 4

    threshold = 10;
    nums = {2,4,8,3,9,12};

    cout << sol.countComponents(nums, threshold) << endl; // 2

    return 0;
}
