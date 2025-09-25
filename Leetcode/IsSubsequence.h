#pragma once

#include <string>
#include <unordered_map>

using string = std::string;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lastPos = -1;
        for (int i = 0; i < s.size(); i++) {
            std::size_t pos = t.find(s[i], lastPos + 1);
            if (pos == string::npos)
                return false;
            lastPos = pos;
        }
        return true;
    }
};