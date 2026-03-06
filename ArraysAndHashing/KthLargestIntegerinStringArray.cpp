#include "../common.hpp"

/*
You are given an array of strings nums and an integer k. Each string in nums represents an integer without leading zeros.

Return the string that represents the kth largest integer in nums.

Note: Duplicate numbers should be counted distinctly.

For example, if nums is ["1","2","2"], "2" is the first largest integer, "2" is the second-largest integer, 

and "1" is the third-largest integer.

Intuitiion
    * use a min heap that keeps minimum in the root (top)
    * iterate over elements pushing them into min heap as ints and pop from min heap when its size grows bigger than k
    * return the top of the min heap 
    * 
pseudo code:
    priority_queue<string, vector<string>, greater<string>>

    for each string element in array
        push to heap 
        if heap size > k
            pop from heap

    return (heap.top())

Time = for each heap operation logk and for k elements total time is klogk. 
Space = 0(k) for the min heap 
*/

// Comparator as a struct
struct Compare {
    bool operator()(const string& a, const string& b) const {
        if (a.size() == b.size())
            return a > b;           // lexicographically larger
        return a.size() > b.size(); // longer string = larger number
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>,  Compare> minHeap;

        for (const string& str : nums){
            minHeap.push(str);

            if (minHeap.size() > k){
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};

int main(){
    Solution sol;

    vector<string> nums = {"3","6","7","10"};

    cout << sol.kthLargestNumber(nums, 4) << endl;

    nums = {"2","21","12","1"};

    cout << sol.kthLargestNumber(nums, 3) << endl;

    nums = {"0","0"};
   
    cout << sol.kthLargestNumber(nums, 2) << endl;

}