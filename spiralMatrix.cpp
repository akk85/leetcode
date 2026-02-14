#include "common.hpp"

/*
intuition
    starting from first cell go right down left up append all cells to our result array
    shrink the matrix borders from all sides by one
    repeat the same. and shrink
    we will stop this iteration once our borders are same meaning no cels in btwn them to explore 

    1  2  3  4  5 
    6  7  8  9  10
    11 12 13 14 15 
    16 17 18 19 20
    
    start at cell 1 left border = first col
                right border = last col
                top border = first row
                botttom border = last row
    go right collect 1 2 3 4 5
    go down collect 10 15 20 go left collect 19 18 17 16 
    go up collect 11 6 shrink borders by 1 repeat the same until borders become same 

*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int n = rows * cols;

        int left  = 0;
        int right = cols - 1;
        int top = 0;
        int bottom = rows - 1;

        while (top <= bottom && left <= right){
            vector<int> currVec = search(matrix, left, right, top, bottom);
            result.insert(result.end(), currVec.begin(), currVec.end());
            left  ++;
            right --;
            top ++;
            bottom --;
        }
        return result;
    }

    vector<int> search(vector<vector<int>>& matrix, int left, int right, int top, int bottom){
        vector<int> res;
        // go right
        for (int col = left; col <= right; col++){
            res.push_back(matrix[top][col]);
        }

        // go down
        for (int row = top + 1; row <= bottom; row++){
            res.push_back(matrix[row][right]);
        }

        // go left 
        if (top != bottom){
            for (int col = right - 1; col >= left; col--){
                res.push_back(matrix[bottom][col]);
            }
        }

        // go up
        if (left != right){
            for (int row = bottom - 1; row > top; row--){
                res.push_back(matrix[row][left]);
            }
        }

        return res;
    }
};

void printResult(const vector<int>& result) {
    for (const int& val : result) cout << val << " ";
    cout << endl;
}

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 2,  3,  4},
        {5, 6,  7,  8},
        {9, 10, 11, 12},
    };

    // vector<vector<int>> matrix = {
    //     {1, 2, 3,   4},
    //     {5, 6, 7,    8},
    //     {9, 10, 11, 12},
    //     {13, 14, 15, 16},
    //     {17, 18, 19, 20}
    // };

    vector<int> result = sol.spiralOrder(matrix);

    printResult(result); 
    // Output: 1 2 3 4 8 12 16 20 19 18 17 13 9 5 6 7 11 15 14 10
}
