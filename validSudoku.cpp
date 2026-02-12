#include "common.hpp"

/*
You are given a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:

Each row must contain the digits 1-9 without duplicates.
Each column must contain the digits 1-9 without duplicates.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
Return true if the Sudoku board is valid, otherwise return false

Note: A board does not need to be full or be solvable to be valid.

Thought process:
    1. iterate over each row and using a set check if curr value exists in set 
    2. iterate over each cols and using a set check if curr value exists in set
    3. iterate over each square and using a set check if curr value exists in set

    instead of three passes I could do so using a set for each row
    create a hashmap of rows that takes a row as a key and a set as the value
    create a hashmap of cols that takes a col as a key and a set as the value
    create a hashmap for each 3 * 3 matrix

    here for the square matrix we could be cleaver and for each 3 * 3 row col map that as one key and one set
    i.e divide each row and col by 3 to find it's respective square row col rep
    so 0 1 2 - 0 
    3 4 5 - 1
    6 7 8 - 2

    this will allows us to just do one single pass

    pseudo code
    for each row in rows
        for each col in cols
            if grid[row][col] == '.' continue 
            cell = grid[row][col]
            if (cell in rowset or cell in colset or cell in squareset)
                return false
            else 
                add cell to rowset
                add cell to colset
                add cell to squareset

    return true

    time is O(9*9) = O(1) but for a general graph O(n^2)
    space is 3 * O(N^2) = 0(n^2)
*/
class Solution{
public:
    bool isValidSudoku(vector<vector<char>>& grid){
        unordered_map<int,            unordered_set<char>> rowsMap;
        unordered_map<int,            unordered_set<char>> colsMap;
        map<pair<int, int>, unordered_set<char>> squareMap;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                char cell = grid[row][col];
                int squareRow = row / 3; int squareCol = col / 3;
                if (cell == '.') continue;
                if (rowsMap[row].contains(cell) || colsMap[col].contains(cell) || squareMap[{squareRow, squareCol}].contains(cell)){
                    return false;
                }

                rowsMap[row].insert(cell);
                colsMap[col].insert(cell);
                squareMap[{squareRow, squareCol}].insert(cell);
            }
        }

        return true;
    }
};

int main(){
    Solution sol;

    
    vector<vector<char>> board = {
                        {'1','2','.','.','3','.','.','.','.'},
                        {'4','.','.','5','.','.','.','.','.'},
                        {'.','9','8','.','.','.','.','.','3'},
                        {'5','.','.','.','6','.','.','.','4'},
                        {'.','.','.','8','.','3','.','.','5'},
                        {'7','.','.','.','2','.','.','.','6'},
                        {'.','.','.','.','.','.','2','.','.'},
                        {'.','.','.','4','1','9','.','.','8'},
                        {'.','.','.','.','8','.','.','7','9'}
                    };


    cout << boolalpha << sol.isValidSudoku(board) << endl;
    board = {
                        {'1','2','.','.','3','.','.','.','.'},
                        {'4','.','.','5','.','.','.','.','.'},
                        {'.','9','1','.','.','.','.','.','3'},
                        {'5','.','.','.','6','.','.','.','4'},
                        {'.','.','.','8','.','3','.','.','5'},
                        {'7','.','.','.','2','.','.','.','6'},
                        {'.','.','.','.','.','.','2','.','.'},
                        {'.','.','.','4','1','9','.','.','8'},
                        {'.','.','.','.','8','.','.','7','9'}
                    };               
                    
    cout << boolalpha << sol.isValidSudoku(board) << endl;
}