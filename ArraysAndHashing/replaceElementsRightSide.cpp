#include "../common.hpp"


class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxSoFar = -1;

        for (int i = n - 1; i >= 0; i--){
            int temp = arr[i];
            arr[i] = maxSoFar;
            maxSoFar = max(maxSoFar, temp);
        }

        return arr;
    }

    void print(vector<int> vec){
        for (const int& num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
};

/*

maxVal = 5
2 2
1 2
3 2
5 3
4 5
2 5
*/

int main(){
    Solution sol;
    vector<int> nums = {2,4,5,3,1,2};     
                    //  5 5 3 2 2 -1 

    sol.replaceElements(nums);
    sol.print(nums);

    vector<int> nums2 = {3,3}; // 3, -1
    sol.replaceElements(nums2);
    sol.print(nums2);

}