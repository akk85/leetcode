#include "common.hpp"

/*
You are given an array asteroids of integers representing asteroids in a row. 

The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, 
and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. 

If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. 

Two asteroids moving in the same direction will never meet.

thought process:
    a collison will happen if there is an asteroid moving right and another asteriood moving left 

    use a flag to know if current astoreoid has been destroyed and whether we should push it to stack

    [-1 5 -3 6 -2]

    [-1 5 6 ]
    diff = 

    pesudeo code
    stack 
    for each asteroid in asteroid
        while stack and stack.top > 0 and asteroid < 0 
            if (top > asteroid)
                break
            if top < asteroid 
                stack.pop
            if top. == asteroid
                pop
                break
        

        stack.push(asteroid)


*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for (const int& asteroid : asteroids){
            bool destroyed = false;
            while (!stk.empty() && stk.back() > 0 && asteroid < 0){
                int stackTopAbs = abs(stk.back());
                int asteroidAbs = abs(asteroid);

                if (stackTopAbs > asteroidAbs){
                    destroyed = true;
                    break;
                } 
                else if (stackTopAbs < asteroidAbs){
                    stk.pop_back();
                }
                else {
                    stk.pop_back();
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed){
                stk.push_back(asteroid);
            }
        }
        return stk;
    }

/*
2,4,-4,-1

stk = 
*/
};

void printResult(const vector<int>& result){
    for (const int& val : result){
        cout << val << " ";
    }
    cout << endl;
}
int main(){
    Solution sol;

    vector<int> asteroids = {2,4,-4,-1};
    vector<int> result = sol.asteroidCollision(asteroids);

    printResult(result);
}