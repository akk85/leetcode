#include "../common.hpp"

/*
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices 
left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
*/

class NumArray1 {
private:
    const vector<int> vec;
public:
    NumArray1(vector<int>& nums) : vec(nums) {};
    
    int sumRange(int left, int right) {
        int sum {};
        while (left <= right){
            sum += vec[left];
            left++;
        }

        return sum;
    }
};
/*
prefix = 0 1 3 6 10 15 
nums   = 1 2 3 4 5            l= 0. r = 4

*/
class NumArray2{
private:
    vector<int> prefix;
public:
    NumArray2(vector<int>& nums) : prefix(nums.size() + 1, 0) {
        for (int i = 0; i < static_cast<int>(nums.size()); i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};
/*
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);

*/

int main(){
                    //  0  1   2   3  4  5
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray1* obj = new NumArray1(nums);  int left = 0; int right = 2;
    cout << obj->sumRange(left, right) << endl;      // 1

    left = 2; right = 5;
    cout << obj->sumRange(left, right) << endl;     // -1

    left = 0; right = 5;
    cout << obj->sumRange(left, right) << endl;     // -3



                    //  0  1   2   3  4  5
    nums = {-2, 0, 3, -5, 2, -1};
    NumArray2* obj2 = new NumArray2(nums);   left = 0;  right = 2;
    cout << obj2->sumRange(left, right) << endl;      // 1

    left = 2; right = 5;
    cout << obj2->sumRange(left, right) << endl;     // -1

    left = 0; right = 5;
    cout << obj2->sumRange(left, right) << endl;     // -3
}

