#include "common.hpp"
/*

Thought process
    1. Use two pointers one at each ends
    2. find current area
    3. update max area with this area if its much bigger than current max area
    4. shift the shortest pointer height and repeat until our pointers meet
    5. return maxarea
*/
class Solution{
public:
    int areaOfLargestContainer(vector<int>& heights){
        int l = 0;
        int r = heights.size() - 1;

        int area = {};
        while (l < r){
            int currentArea = min(heights[l], heights[r]) * (r -l);
            area = max(area, currentArea);
            if (heights[l] < heights[r]){
                l++;
            } else {
                r--;
            }
        }

        return area;
    }
};

int main(){
    Solution sol;

    vector<int> heights = {1,7,2,5,4,7,3,6};

    cout << sol.areaOfLargestContainer(heights) << endl;

    heights = {2,2,2};

    cout << sol.areaOfLargestContainer(heights) << endl;
}