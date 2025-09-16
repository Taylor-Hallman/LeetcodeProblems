#pragma once

#include <vector>
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int reversed = 0;
        for (int n = x; n > 0; n /= 10) {
            reversed = reversed * 10 + n % 10;
        }

        return reversed == x;
    }
};