#include "common.hpp"

/*
A binary string is monotone increasing if it consists of some number of 0's (possibly none), 
followed by some number of 1's (also possibly none).

You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

Return the minimum number of flips to make s monotone increasing.

Thought Process:
    1. as we iterate the string we can keep a count of how many 1's we seen 
    2. when we get a 0 we have the option of either flipping it to 1 or flipping the ones we've seen before into a 0
    3. we make the decision my taking the min btwn the number of 1's and a running total that we will be keeping 

    pseudo code
    int res = 0
    for each num in the string
        if num is 1
            update countones;
        else it's zero
            increasing flip 
            and update flip to min of zerocount and this flip 
*/
class StringFlip{
public:
    int minFlipsMonoIncr(string s) {
        int flip = 0;
        int onesCount = 0;
        for (const char num : s){
            if (num == '1'){
                onesCount += 1;
            } else {
                flip += 1;
                flip = min(onesCount, flip);
            }
        }
        return flip;
    }
};

int main(){
    StringFlip flip;

    string s = "00110";      // 1
    cout << flip.minFlipsMonoIncr(s) << endl;

    s = "010110";     // 2
    cout << flip.minFlipsMonoIncr(s) << endl;

    s = "00011000";   // 2
    cout << flip.minFlipsMonoIncr(s) << endl;
}