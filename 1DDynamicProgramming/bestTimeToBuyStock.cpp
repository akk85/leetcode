#include "../common.hpp"

class Solution{
public:
    int maxProfit(vector<int>& prices){
        int buy = prices[0];
        int n = prices.size();
        int maxProfit {};
        for (int i = 1; i < n; i++){
            if (prices[i] < buy){
                buy = prices[i];
            } else {
                int profit = prices[i] - buy;
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
};

int main(){
    Solution sol;

    vector<int> prices = {10,1,5,6,7,1};
    cout << sol.maxProfit(prices) << endl;

    prices = {10,8,7,5,2};
    cout << sol.maxProfit(prices) << endl;
}

