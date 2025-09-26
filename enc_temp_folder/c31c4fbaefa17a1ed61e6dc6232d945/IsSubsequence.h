#pragma once

#include <string>
#include <unordered_map>

using string = std::string;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lastPos = -1;
        for (int i = 0; i < s.size(); i++) {
            std::size_t pos = t.find(s[i]);
            if (pos == string::npos || (int)pos < lastPos)
                return false;
            lastPos = pos;
        }
        return true;
    }
};