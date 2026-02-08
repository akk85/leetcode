#include "common.hpp"

/*
Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.

A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. 

The elements do not have to be consecutive in the original array.

You must write an algorithm that runs in O(n) time.

Thought process using a hashset for constant time lookup
    1. add all values from nums to a set
    2. iterate through the array
        * for each value we check if its a starting sequence meaning its value - 1 is not in set
        * if so we count all occurences of consecutive number starting from this position in set
        * update our longest variable to maximum of this and do so for each starting sequence number
    Time  -> O(n) we iterate over n items twice
    space -> O(n) we store at worst case n items in our set 
*/
class Solution{
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        for (const int& num : nums){
            seen.insert(num);
        }
        int longest {};
        for (const int& num : nums){
            // check if it's a starting sequence number
            if (!seen.contains(num - 1)){
                int length = 1;
                int next = num + 1;
                while (seen.contains(next)){
                    length ++;
                    next ++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {2,20,4,10,3,4,5};

    cout << sol.longestConsecutive(nums) << endl;  // 4

    nums = {0,3,2,5,4,6,1,1};

    cout << sol.longestConsecutive(nums) << endl; // 7 
}