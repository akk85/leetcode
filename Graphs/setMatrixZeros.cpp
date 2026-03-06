#include "../common.hpp"

/*
Given an m x n matrix of integers matrix, if an element is 0, set its entire row and column to 0's.

You must update the matrix in-place.

Follow up: Could you solve it using O(1) space?

thought process:
    use first row and first column as markers
    1. iterate over first row and first column and set flags if they have zeros
    2. iterate over rest of grid and if cell is a zero mark respective cell and row as zero
    3. iterate over cells check if first row cell or first column cell has zero and mark cell if true 
    3. if flags true iterate over first row and first columm marking all cells zero.
*/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size(); 

        // flags
        bool zeroFirstRow = false;
        bool zeroFirstCol = false;
        for (int col = 0; col < cols; col++){
            if (matrix[0][col] == 0) zeroFirstRow = true;
        }

        for (int row = 0; row < rows; row++){
            if (matrix[row][0] == 0) zeroFirstCol= true;
        }

        // mark first row and first col with 0 
        for (int row = 1; row < rows; row ++){
            for (int col = 1; col < cols; col++){
                if (matrix[row][col] == 0){
                    matrix[row][0] = 0;    // mark this row to be zeroed
                    matrix[0][col] = 0;    // mark this col to be zeroed
                }
            }
        }

        // mark all cells if first row or first col is zero
        for (int row = 1; row < rows; row ++){
            for (int col = 1; col < cols; col++){
                if (matrix[row][0] == 0 || matrix[0][col] == 0){
                    matrix[row][col] = 0;
                }
            }
        }

        // mark first row and column based on flags 
        if (zeroFirstRow){
            for (int col = 0; col < cols; col++){
                matrix[0][col] = 0;
            }
        }
        if (zeroFirstCol){
            for (int row = 0; row < rows; row++){
                matrix[row][0] = 0;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    sol.setZeroes(matrix);

    for (auto& row : matrix) {
        for (auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

