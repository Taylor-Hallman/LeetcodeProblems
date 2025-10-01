#pragma once

#include <string>
#include <vector>

using string = std::string;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::vector<int> indexS(256, 0);
        std::vector<int> indexT(256, 0);

        for (int i = 0; i < s.length(); i++) {
            if (indexS[s[i]] != indexT[t[i]])
                return false;

            indexS[s[i]] = i + 1;
            indexT[t[i]] = i + 1;
        }
    }
};