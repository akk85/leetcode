#include "../common.hpp"

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> incomingEdges(n, 0);
        for (const vector<int>& edge : edges){
            int dst = edge[1];
            incomingEdges[dst] += 1;
        }

        vector<int> result;
        for (int node = 0; node < n; node ++){
            if (incomingEdges[node] == 0){
                result.push_back(node);
            }
        }

        return result;
    }
};
void printVector(vector<int>& result){
    for (const int& val : result){
        cout << val << " ";
    }
    cout << endl;
}
int main(){
    Solution sol;
    
    vector<vector<int>> edges = {
        {0,1},
        {0,2},
        {2,5},
        {3,4},
        {4,2}
    };

    vector<int> result = sol.findSmallestSetOfVertices(6, edges);

    printVector(result); // 0, 3
}