#include "../common.hpp"

/*
Given a square n x n matrix of integers matrix, rotate it by 90 degrees clockwise.

You must rotate the matrix in-place. Do not allocate another 2D matrix and do the rotation.

Thought process:
    Step 1: Transpose the matrix for each cell above the diagonal
    Step 2: Reverse each row 

Time: O(n * n) — visiting each element once in transpose + reverse
Space: O(1) - completely in place 
*/

class Solution {
public:
    // helper for swapping values in place 
    void mySwap(int& first, int& second){
        int temp = first;
        first = second;
        second = temp;
    }

    // helper for reversing a vector row
    void myReverse(vector<int>& vec){
        int left  = 0;
        int right = vec.size() - 1;

        while (left < right){
            mySwap(vec[left], vec[right]);
            left  ++;
            right --;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // transpose above diagonal
        for (int row = 0; row < n; row++){
            for (int col = row + 1; col < n; col++){
                mySwap(matrix[row][col], matrix[col][row]);
            }
        }

        // reverse each row
        for (int row = 0; row < n; row++){
            myReverse(matrix[row]);
        }
    }
};

void printResult(const vector<vector<int>>& result){
    for (const vector<int>& vec : result){
        for (const int& val : vec){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    Solution sol;

    // Test Case 1
    vector<vector<int>> matrix = {
        {1,2},
        {3,4}
    };

    printResult(matrix);

    sol.rotate(matrix);     // 3 1
                            // 4 2

    printResult(matrix);

    // Test Case 2
    matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    printResult(matrix);

    sol.rotate(matrix);     // [7,4,1],
                            // [8,5,2],
                            // [9,6,3]


    printResult(matrix);

    
}