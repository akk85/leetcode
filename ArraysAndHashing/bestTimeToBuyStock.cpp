#include "../common.hpp"

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
class Solution{
public:
    int maxProfit(vector<int>& prices){
        int buy = prices[0];

        int maxProfit = 0;
        for (int right = 1; right < (int)prices.size(); right ++){
            int currDay = prices[right];
            if (currDay > buy){
                int profit = currDay - buy;
                maxProfit = max(maxProfit, profit);
                continue;
            }
            buy = currDay; 
        }
        return maxProfit;
    }
};

int main(){
    Solution sol;

    vector<int> prices = {10,1,5,6,7,1}; // 6
    cout << sol.maxProfit(prices) << endl;

    prices = {10,8,7,5,2}; // 0
    cout << sol.maxProfit(prices) << endl;
}

