#include "../common.hpp"

/*
Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. 

In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. 

At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

Thought process:

A battleship is one connection of ships conencted togeether.

We can avoid using extra space by just counting the first ships of each battleship
Since a battleship can only be verticle and horizontal for a verticle connection the top ship wil not have a ship above it and for a 
hprizontal batkleship, the first ship will not have ny ship to its left.

so if any ships matches this creatria we know its a starting ship and we can increment count and just skip counting the other hsips in this connection


*/
#define SHIP 'X'
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();

        int battleShips = 0;
        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col ++){
                if ((board[row][col] == SHIP) &&  (row == 0 || board[row - 1][col] != SHIP) && (col == 0 || board[row][col - 1] != SHIP))
                battleShips ++;
            }
        }
        return battleShips;
    }

};

int main(){
    Solution sol;

    vector<vector<char>> board = {
                                {'X', '.', '.', 'X'},
                                {'.', '.', '.', 'X'},
                                {'.', '.', '.', 'X'}
    };

    cout << sol.countBattleships(board) << endl; // 2

    board = {{'X'}}; 

    cout << sol.countBattleships(board) << endl; // 1

    board = {{'.'}}; 

    cout << sol.countBattleships(board) << endl; // 0

}