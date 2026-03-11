#include "../common.hpp"

/*
You are given an m x n integer matrix grid and an array queries of size k.

Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and 
repeat the following process:

If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your 
first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.

Otherwise, you do not get any points, and you end this process.
After the process, answer[i] is the maximum number of points you can get. 
Note that for each query you are allowed to visit the same cell multiple times.

Return the resulting array answer.
*/

class Solution {
private:
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rows = grid.size(), cols = grid[0].size();

        // sort the queries 
        vector<pair<int, int>> indexedQueries;
        for (int index = 0; index < queries.size(); index ++){
            indexedQueries.push_back({queries[index], index});
        }

        sort(indexedQueries.begin(), indexedQueries.end());

        // minheap and vector for tracking visited cells
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int points = 0;
        vector<int> ans(queries.size());
        for (const auto& [query , index] : indexedQueries){
            while (!minHeap.empty() && get<0>(minHeap.top()) < query){ // grid value is less than query

                auto [cell, row, col] = minHeap.top(); minHeap.pop();
                points ++;

                for (const auto& [dr, dc] : directions){
                    int nr = row + dr;
                    int nc = col + dc;

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]){
                        minHeap.push({grid[nr][nc], nr, nc});
                        visited[nr][nc] = true;
                    }
                }
            }
            ans[index] = points;
        }

        return ans;
    }
};

void printResult(const vector<int>& result){
    for (const int& val : result){
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    Solution sol;

    vector<vector<int>> grid = {{1,2,3},{2,5,7},{3,5,1}};
    vector<int> queries = {5,6,2};

    vector<int> ans = sol.maxPoints(grid, queries);

    printResult(ans); // 5, 8, 1
}