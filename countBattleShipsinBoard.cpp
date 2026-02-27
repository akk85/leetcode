#include "common.hpp"

/*
A battleship is one connection of ships conencted togeether.
We can just iterate over grid once, when we encounter a ship, mark all its connected ships as water increment count and continue 
*/
#define SHIP 'X'
#define VISITED '.'
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();

        int battleShips = 0;
        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col ++){
                if (board[row][col] == SHIP){
                    bfs(board, row, col);
                    battleShips ++;
                }
            }
        }

        return battleShips;
    }
private:
    vector<pair<int, int>> directions = {{0,-1}, {0, 1}, {-1, 0}, {1, 0}};
    void bfs(vector<vector<char>>& board, int row, int col){
        int rows = board.size(), cols = board[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});

        board[row][col] = VISITED;

        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();

            for (const auto& [dr, dc] : directions){
                int nRow = row + dr;
                int nCol = col + dc;

                if (nRow >=0 && nRow <= rows - 1 && nCol >= 0 && nCol <= cols - 1 && board[nRow][nCol] == SHIP){
                    q.push({nRow, nCol});
                    board[nRow][nCol] = VISITED;
                }
            }
        }
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