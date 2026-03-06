#include "../common.hpp"
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
        int left  = 0;
        int right = heights.size() - 1;

        int maxArea = 0;
        while (left < right){
            int currHeight = min(heights[left], heights[right]);
            int distance   = right - left;

            int area       = currHeight * distance;

            maxArea        = max(maxArea, area);

            if (heights[left] < heights[right]) left ++;
            else right --;
        }

        return maxArea;
    }
};

int main(){
    Solution sol;

    vector<int> heights = {1,8,6,2,5,4,8,3,7}; 

    cout << sol.areaOfLargestContainer(heights) << endl; // 49

    heights = {2,2,2};

    cout << sol.areaOfLargestContainer(heights) << endl; // 4 
}