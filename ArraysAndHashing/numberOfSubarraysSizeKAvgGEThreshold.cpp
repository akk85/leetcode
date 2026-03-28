#include "../common.hpp"

/*
Given an array of integers arr and two integers k and threshold, 
return the number of sub-arrays of size k and average greater than or equal to threshold.
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        double sum  = 0;
        int left = 0;
        int count = 0;
        for (int right = 0; right < (int)arr.size(); right ++){
            sum += arr[right];

            if (right - left + 1 > k){
                sum -= arr[left];
                left ++;
            }
            if (right - left + 1 == k){
                double average = sum / (right - left + 1);
                if (average >= threshold)  count ++;
            }
        }
        return count;
    }
};

int main(){
    Solution sol;

    vector<int> arr = {2,2,2,2,5,5,5,8};

    cout << sol.numOfSubarrays(arr, 3, 4) << endl; // 3

    arr = {11,13,17,23,29,31,7,5,2,3};

    cout << sol.numOfSubarrays(arr, 3, 5) << endl; // 6
}