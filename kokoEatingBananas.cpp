#include "common.hpp"

class Solution{
public:
    int minimumEatingSpeed(vector<int>& piles, int h){
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        int result = r;

        while (l <= r){
            int k = l + (r - l) / 2;
            long long hours = 0;
            for (const int& pile : piles){
                hours += ceil(double(pile) / k);
            }

            if (hours <= h){
                result = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }

        return result;
    }
};

int main(){
    Solution sol;
    vector<int> piles = {1, 4, 3, 2};
    cout << sol.minimumEatingSpeed(piles, 9) << endl; // 2

    piles = {25,10,23,4};
    cout << sol.minimumEatingSpeed(piles, 4) << endl; // 25
}

/*
1 4 3 2            h = 4

1 2 3 4
*/