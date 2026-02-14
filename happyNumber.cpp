#include "common.hpp"

/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

intuition
    1. Repeatedly replace number with sum of squares of digits.
    2. If we reach 1 → happy number.
    3. If we enter a cycle → not happy.
    4. Instead of using a set, use slow/fast pointers (Floyd’s cycle detection).
        slow moves 1 step
        fast moves 2 steps
    5. If fast becomes 1 → return true.
    6. If slow meets fast → cycle → return false.


*/
class Solution {
public:
    bool isHappy(int num) {
        int slow = num;
        int fast = num;

        while (true){
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));

            if (fast == 1) return true;
            if (slow == fast) return false;
        }
        return true;
    }

    int squareSum(int num){
        int sum {};
        while (num > 0){
            int digit = num % 10;
            int square = digit * digit;
            sum += square;
            num = num / 10;
        }

        return sum;
    }
};


int main(){
    Solution sol;

    cout << boolalpha << sol.isHappy(1) << endl;
}