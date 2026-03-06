#include "../common.hpp"

/*
You are given an 2-D array points where points[i] = [xi, yi] represents

the coordinates of a point on an X-Y axis plane. You are also given an integer k.

Return the k closest points to the origin (0, 0).

The distance between two points is defined as the Euclidean distance (sqrt((x1 - x2)^2 + (y1 - y2)^2)).

You may return the answer in any order.

maintain a heap of size k
    if heap grows bigger than k we pop the top element which will be the biggest distance 
    use a max heap
    for each point find the Euclidean distance (sqrt((x1 - x2)^2 + (y1 - y2)^2)).
*/

class Solution {
private:
    int getEuclideandistance(const vector<int>& point){
        int x = point[0];
        int y = point[1];

        return x * x + y * y;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (const vector<int>& point : points){
            int distance = getEuclideandistance(point);

            maxHeap.push({distance, point});

            if (maxHeap.size() > k)  maxHeap.pop();
               
        }

        vector<vector<int>> result;

        while(!maxHeap.empty()){
            result.push_back(maxHeap.top().second); maxHeap.pop();
        }

        return result;
    }
};

void printResult(vector<vector<int>>& result){
    for(const vector<int>& vec : result){
        for (const int& val : vec){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main(){
    Solution sol;

    vector<vector<int>> points = {{0,2},{2,2}};

    vector<vector<int>> result = sol.kClosest(points, 1);

    printResult(result);

    points = {{0,2},{2,0},{2,2}};

    result = sol.kClosest(points, 2);

    printResult(result);
}