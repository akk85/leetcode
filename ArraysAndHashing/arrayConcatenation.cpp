#include "../common.hpp"

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(2 * n);
        
        for (int i = 0; i < n; i++){
            vec[i]     = nums[i];
            vec[i + n] = nums[i];
        }
        return vec;
    }

    void print(vector<int> vec){
        for (const int& num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,1,2,3};       // 0,1,2,3
    vector<int> res = s.getConcatenation(nums);

    s.print(res);


}