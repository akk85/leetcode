#include "../common.hpp"

/*
Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and 
lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix 
inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.

Thougth process:
    store each mini rectangle sum as a prefix in the bottom right cell
    sum of any bounded rectangel = sum of big rectangle  - top rectangle - left rectange 
    will need to add top left cell since we double subtract it twice in top rectangle and left rectangle 
*/
class NumMatrix {
private:    
    vector<vector<int>> gridSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        gridSum.resize(rows + 1, vector<int>(cols + 1, 0));

        for (int row = 0; row < rows; row ++){
            int prefix = 0;
            for (int col = 0; col < cols; col ++){
                prefix += matrix[row][col];
                
                int aboveSum = gridSum[row][col + 1];
                gridSum[row + 1][col + 1] = prefix + aboveSum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1 = row1 + 1; col1 = col1 + 1; row2 = row2 + 1; col2 = col2 + 1;
        int bottomSum     = gridSum[row2][col2];
        int aboveSum      = gridSum[row1 - 1][col2];
        int leftSum       = gridSum[row2][col1 - 1];
        int topleftSum    = gridSum[row1 - 1][col1 - 1];

        int regionSum = bottomSum - aboveSum - leftSum + topleftSum;
        
        return regionSum;
    }
};