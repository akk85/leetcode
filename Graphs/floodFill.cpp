#include "../common.hpp"

/*
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

*/

class Solution {
private:
    const vector<vector<int>> directions = {{0, -1}, {0, 1},{-1, 0}, {1, 0}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;

        int startingPixel = image[sr][sc];

        queue<pair<int, int>> q;
        q.push({sr,sc});

        image[sr][sc] = color;

        bfs(image, q, color, startingPixel);
        return image;
    }

    void bfs(vector<vector<int>>& image, queue<pair<int, int>>& q, int color, int startingPixel){
        const int rows = image.size(); const int cols = image[0].size();
        
        while (!q.empty()){
            auto [row, col] = q.front(); q.pop();

            for (vector<int> dir : directions){
                int nr = row + dir[0];
                int nc = col + dir[1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && image[nr][nc] == startingPixel){
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
    }
};

void printResult(vector<vector<int>>& result){
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
int main() {
    Solution sol;
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr = 1;
    int sc = 1;
    int color = 2;

    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);
    printResult(result);

    return 0;
}