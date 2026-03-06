#include "../common.hpp"

/*
Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

Each product is guaranteed to fit in a 32-bit integer.
Thought process using division:
    1. find the total product for the array 
        * skip zeros but also keep a count of zeros
    2. if count of zeros is more than 1 then just return an array of zeros because product of array withiut self will always be zero
    3. if count of zeros is 1 or less:
        * if zero is only 1 then this position gets the product but other positions get zero
        * if no zero then product value at each position is product / value 
    
    Time -> O(n) Space O(1)

Follow-up: Could you solve it in  O(n) time without using the division operation?
Thought process using prefix and postfix sum:
    1. using two arrays we can compute the product of each index before it and after it and the product withut self 
    will be prefix[i] * postfix[i]
    2. to build the prefix array, we assume the product before position 1 is 1 and start from 2nd index
    2. same fashion for postfix and do the same in reverse 
    Time -> O(n) Space O(n)
*/
class Solution{
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n = nums.size();
        int zeroCount {};
        int product = 1;
        for (const int& num : nums){
            if (num != 0){
                product *= num;
            } else {
                zeroCount ++;
            }
        }

        if (zeroCount > 1){
            return vector<int> (n, 0);
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++){
            if (zeroCount == 1){
                if (nums[i] == 0){
                    res[i] = product;
                } else {
                    res[i] = 0;
                }
            } else {
                res[i] = product / nums[i];
            }
        }
        return res;
    }

    void print(const vector<int>& vec){
        for (const int& val : vec){
            cout << val << " ";
        }
        cout << endl;
    }

    vector<int> productExceptSelf2(vector<int>& nums){
        int n = nums.size();
        vector<int> prefix (n, 1);
        vector<int> postfix(n, 1);

        for (int i = 1; i < n; i++){
            prefix[i] = nums[i - 1] * prefix[i -1]; 
        }

        for (int i = n - 2; i >= 0; i--){
            postfix[i] = nums[i + 1] * postfix[i + 1];
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++){
            res[i] = prefix[i] * postfix[i];
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,4,6};

    vector<int> res = sol.productExceptSelf(nums);
    sol.print(res);
    res = sol.productExceptSelf2(nums);
    sol.print(res);

    nums = {-1,0,1,2,3};
    res = sol.productExceptSelf(nums);
    sol.print(res);
    res = sol.productExceptSelf2(nums);
    sol.print(res);


    nums = {0,1,0,3,4};
    res = sol.productExceptSelf(nums);
    sol.print(res);
    res = sol.productExceptSelf2(nums);
    sol.print(res);

}