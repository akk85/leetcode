#include "common.hpp"

/*
Given a 2-D grid of characters board and a string word, 

return true if the word is present in the grid, otherwise return false.

For the word to be present it must be possible to form it with a path in the board with

horizontally or vertically neighboring cells. The same cell may not be used more than once in a word.


Thought process:
    1. get all cells having starting char of word
    2. run bfs from this cells checking if neighbors == next char if so add to queue and update pointer 

*/

class Solution {
private:
    set<pair<int, int>> visited;
public:
    bool exist(vector<vector<char>>& board, string word) {
    }

};
