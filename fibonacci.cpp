#include "common.hpp"

class Solution{
public:
    int fibonacci(int n){
        unordered_map<int, int> map;

        map[0] = 0;
        map[1] = 1;

        for (int i = 2; i <= n; i++){
            map[i] = map[i - 1] + map[i - 2]; 
        }

        return map[n];
    }
};

int main(){
    Solution sol;

    cout << sol.fibonacci(5) << endl;
}