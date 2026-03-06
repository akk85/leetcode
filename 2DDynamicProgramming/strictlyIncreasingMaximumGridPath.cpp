#include "../common.hpp"

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    }


};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    vector<vector<int>> grid2 = {
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}
    };

    cout << "Test 1: " << sol.longestIncreasingPath(grid1) << endl; 
    // Expected: 4

    cout << "Test 2: " << sol.longestIncreasingPath(grid2) << endl; 
    // Expected: 4

    return 0;
}
