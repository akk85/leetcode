#include "../common.hpp"

/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

Intuition:
    use a map of size k
    sliding window when this window has more than two distinct fruits start shrinking from left
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> fruitMap; // fruit -> frequency
        int left = 0;
        int maxFruits = 0;
        for (int right = 0; right < (int)fruits.size(); right ++){
            fruitMap[fruits[right]] ++;

            while(fruitMap.size() > 2){
                fruitMap[fruits[left]] --;
                if (fruitMap[fruits[left]] == 0) fruitMap.erase(fruits[left]);
                left ++;
            }

            maxFruits = max(maxFruits, right - left + 1);
        }
        return maxFruits;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {1,2,1};
    cout << sol.totalFruit(nums) << endl; // 3

    nums = {0,1,2,2};
    cout << sol.totalFruit(nums) << endl; // 3

    nums = {1,2,3,2,2};
    cout << sol.totalFruit(nums) << endl; // 4
}