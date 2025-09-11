#pragma once

#include <string>

using string = std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        string big, small;
        if (a.size() > b.size()) {
            big = a;
            small = b;
        }
        else {
            big = b;
            small = a;
        }

        string leading = "";
        for (int i = 0; i < (big.size() - small.size()); i++) {
            leading += '0';
        }
        small = leading + small;

        string result = "";

        int carry = 0;
        for (int i = small.size() - 1; i >= 0; i--) {
            int sum = (small[i] - '0') + (big[i] - '0') + carry;
            if (sum > 1) {
                carry = 1;
                result += (sum % 2) + '0';
            }
            else {
                carry = 0;
                result += sum + '0';
            }
        }
        if (carry == 1)
            result += '1';
        std::reverse(result.begin(), result.end());

        return result;
    }
};