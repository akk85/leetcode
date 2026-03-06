#include "../common.hpp"

/*
You are given a 2-D matrix board containing 'X' and 'O' characters.

If a continous, four-directionally connected group of 'O's is surrounded by 'X's, it is considered to be surrounded.

Change all surrounded regions of 'O's to 'X's and do so in-place by modifying the input board.

Thought process:
### Thought Process

1.  Any 'O' connected to the border cannot be surrounded.
    So first, we scan the edges of the board and start a BFS from every border 'O'.  
    While exploring, we temporarily mark those safe 'O's as 'T'.

2.  After marking all border-connected regions, we iterate over the entire board.
   - If a cell is still 'O', it means it was not connected to the border, so it must be surrounded → change it to 'X'.
   - If a cell is 'T', it was marked safe → leave it for now.

3. Finally, iterate once more and convert all 'T' back to 'O' to restore the original safe regions.

*/

#define TEMPORARY 'T'
#define ZERO 'O'
#define X 'X'

class Solution {
public:
    void solve(vector<vector<char>>& board) {

        captureUnsurroundedRegions(board);
        captureSurroundedRegions(board);
        revertUnsurroundedRegions(board);
    }

    void captureUnsurroundedRegions(vector<vector<char>>& board){
        queue<pair<int, int>> q;
        int rows = board.size();
        int cols = board[0].size();
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if ((row == 0 || row == rows - 1 || col == 0 || col == cols - 1) && board[row][col] == ZERO){
                    board[row][col] = TEMPORARY;  // mark immediately
                    q.push({row, col});  // get regions 
                }
            }
        }

        bfs(board, q);  //bfs from queue of border surrounded regions and mark all neighbors as temps 
    }

    void bfs(vector<vector<char>>& board, queue<pair<int, int>>& q){
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> directions {{0, -1},  {0,  1}, {-1, 0}, {1,  0} };

        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();

            for (const vector<int>& dir : directions){
                int nr = row + dir[0];
                int nc = col + dir[1];

                if (nr>=0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == ZERO){
                    board[nr][nc] = TEMPORARY;  // mark temporary
                    q.push({nr, nc});
                }
            }
        }   
    }
    void captureSurroundedRegions(vector<vector<char>>& board){
        int rows = board.size();
        int cols = board[0].size();
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (board[row][col] == ZERO){
                    board[row][col] = X;
                }
            }
        }
    }
    void revertUnsurroundedRegions(vector<vector<char>>& board){
        int rows = board.size();
        int cols = board[0].size();
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (board[row][col] == TEMPORARY){
                    board[row][col] = ZERO;
                }
            }
        }
    }
};

void printBoard(vector<vector<char>>& board){
    for (auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
}
int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','O','O','X'},
        {'X','X','X','O'}
    };

    printBoard(board);
    cout << endl;
    cout << endl;
    sol.solve(board);
    printBoard(board);

    return 0;
}
