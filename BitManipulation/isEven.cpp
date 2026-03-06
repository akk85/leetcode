#include "../common.hpp"


class Solution{
public:
    bool isEven(int x){
        if ((x & 1) == 0){         // 0000 & 0001 == 0000      0001 & 0001 = 0001
            return true;
        }
        return false;
    }

};

int main(){
    Solution sol;
    cout << boolalpha << sol.isEven(2) << endl;
    cout << boolalpha << sol.isEven(3) << endl;
}

