#include "../common.hpp"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int bit = 0; bit < 32; bit++){
            uint32_t bitValue = (n >> bit) & 1;
            res += (bitValue << (31 - bit));
        }

        return res;
    }
};

int main(){
    Solution sol;
    uint32_t n = 00000000000000000000000000010101;

    cout << sol.reverseBits(n) << endl;
}
