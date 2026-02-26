#include "common.hpp"

/*

-3 0 1 2 3 3  t = 3

-1, -1, -1, 1, 1, 1   target = 2
 i
            j
               l
                 r

sum = 2

res = [-1, 1, 1]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};

        vector<vector<int>> result;

        sort(nums.begin(), nums.end());  
        
        

        for (int first = 0; first < n - 3; first ++){
            if (first != 0 && nums[first] == nums[first - 1]) continue;

            for (int second = first + 1; second < n - 2; second ++){
                if (second != first + 1 && nums[second] == nums[second - 1]) continue;

                if ((long long)nums[first] + nums[second] + nums[second + 1] + nums[second + 2] > target) break; // can't find any sum smaller than this hence break from second loop
                
                int left  = second + 1;
                int right = n - 1;
                
                while (left < right){
                    long long sum = static_cast<long long>(nums[first]) + nums[second] + nums[left] + nums[right];
                    if (sum < target)      left  ++;
                    else if (sum > target) right --;
                    else {
                        vector<int> res = {nums[first], nums[second], nums[left], nums[right]};
                        result.push_back(res);
                        left  ++;
                        right --;

                        while(left < right && nums[left] == nums[left - 1]) left ++;
                    }
                }

            }
        }

        return result;
    }
};

void printResult(vector<vector<int>>& result){
    for (const vector<int>& vec : result){
        for (const int& num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    Solution sol;

    vector<int> nums = {3,2,3,-3,1,0};

    vector<vector<int>>  result = sol.fourSum(nums, 3);

    printResult(result);

    nums = {1,-1,1,-1,1,-1};

    result = sol.fourSum(nums, 2);

    printResult(result);
}