#include <cmath>
#include <array>
#include <cstdint>

class Solution {
public:
    int reverseBits(int n) {
        int result = 0;
        for (int i = 1; i < 31; i++) {
            int temp = n & static_cast<int>(std::pow(2, i));
            int shiftAmt = 31 - i * 2;
            int rTemp = shiftAmt < 0 ? temp >> -shiftAmt : temp << shiftAmt;
            result |= rTemp;
        }
        return result;
    }
};