#include "../common.hpp"

/*
You are given an integer array of unique positive integers nums. Consider the following graph:

There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],

There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.

Return the size of the largest connected component in the graph.
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
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();

        // self union each node
        int totalValues = 1e5 + 1;  //total values according to constraint 
        parent.resize(totalValues);
        size.resize(totalValues);
        for (int node = 0; node < totalValues; node++){
            parent[node] = node;
            size[node]   = 1;
        }

        // union each node with its factors 
        for (int i = 0; i < n; i++){
            int node = nums[i];
            for (int factor = 2; factor * factor <= node; factor ++){
                if (node % factor == 0){
                    Union(node, factor);
                    int factor2 = node / factor;
                    if (factor2 != factor){
                        Union(node, factor2);
                    }
                }
            }
        }

        // find biggest component size
        unordered_map<int, int> rootMap;
        for(int i = 0; i < n; i ++){
            int node = nums[i];
            int root = Find(node);
            rootMap[root] ++;
        }

        int largest = 0;
        for (const auto& [root, size] : rootMap){
            largest = max(largest, size);
        }

        return largest;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {4,6,15,35};

    cout << sol.largestComponentSize(nums) << endl; // 4

    nums = {20,50,9,63};

    cout << sol.largestComponentSize(nums) << endl; // 2

    nums = {2,3,6,7,4,12,21,39};

    cout << sol.largestComponentSize(nums) << endl; // 8
}