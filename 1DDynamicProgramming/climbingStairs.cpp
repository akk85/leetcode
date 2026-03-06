#include "../common.hpp"

/*
You are given an integer n representing the number of steps to reach the top of a staircase. 

You can climb with either 1 or 2 steps at a time.

Return the number of distinct ways to climb to the top of the staircase.
*/

class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> map;
        map[0] = 1;
        map[1] = 1;

        for (int i = 2; i <= n; i++){
            map[i] = map[i - 1] + map[i-2];
        }

        return map[n];
    }
};

int main(){
    Solution sol;

    cout << sol.climbStairs(5) << endl;
}
