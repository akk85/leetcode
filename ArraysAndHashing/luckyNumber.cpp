#include "../common.hpp"


/*
You are given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.

1 1
2 2
3 3 

1,2,2,3,3,2

max = 1

2 3
3 2
max = -1
2,2,2,3,3
*/

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> counter;
        for (const int& num : arr){
            counter[num]++;
        }

        int max = -1;
        for (const auto [num, freq] : counter){
            if (num == freq){
                max = std::max(max , freq);
            }
        }
        return max;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1,2,2,3,3,3};        // 3
    cout << sol.findLucky(arr) << endl;

    arr = {2,2,2,3,3};                        // -1 
    cout << sol.findLucky(arr) << endl;

}