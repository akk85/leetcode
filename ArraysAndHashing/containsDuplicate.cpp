#include "../common.hpp"
#include <unordered_set>
#include <unordered_map>
class Solution {
public:
    // sorting the array O(nlogn) time and O(1) extra space 
    // also mutates the input string 
    bool hasDuplicate1(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (size_t i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;
    }
    // using a hashset O(n) time and O(n) space
    bool hasDuplicate2(vector<int>& nums) {
        unordered_set<int> seen;
        for (const int& num : nums){
            if (seen.count(num)){
                return true;
            }
            seen.insert(num);
        }
        return false;
    }

    // using a hashmap and checking frequencies O(n) time and O(n) space
    bool hasDuplicate3(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (const int& num : nums){
            seen[num] += 1;
        }

        for (const auto& pair: seen){
            if (pair.second != 1){
                return true;
            }
        }
        return false;
    }
    
    // one liner quick 
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());

        return nums.size() != seen.size();
    }


};


int main(){
    Solution s;
    vector<int> nums1  = {1, 2, 3, 3};
    cout << boolalpha << s.hasDuplicate1(nums1) << endl;
    cout << boolalpha << s.hasDuplicate2(nums1) << endl;
    cout << boolalpha << s.hasDuplicate3(nums1) << endl;

    vector<int> nums2 = {1, 2, 3, 4};
    cout << boolalpha << s.hasDuplicate1(nums2) << endl;
    cout << boolalpha << s.hasDuplicate2(nums2) << endl;
    cout << boolalpha << s.hasDuplicate3(nums2) << endl;
}