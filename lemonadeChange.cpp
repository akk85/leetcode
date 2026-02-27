#include "common.hpp"

/*
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). 

Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 

You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

You are given an integer array bills where bills[i] is the bill the ith customer pays, 

return true if you can provide every customer with the correct change, or false otherwise.
*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens  = 0;
        for (const int& bill : bills){
            if  (bill == 5)  {
                fives ++;
            }
            else if (bill == 10) {
                tens ++;
                if (fives > 0) {
                    fives --;
                }
                else {
                    return false;
                }

            }
            else {
                int change = bill - 5;

                if (change == 15 and tens > 0 && fives > 0){
                    tens  --;
                    fives --;
                }
                else if (change == 15 and fives >= 3){
                    fives -= 3;
                }
                else {
                    return false;
                }
            }

        }

        return true;
    }
};