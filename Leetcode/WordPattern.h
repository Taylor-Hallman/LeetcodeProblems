#pragma once

#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
    using string = std::string;
public:
    bool wordPattern(string pattern, string s) {
        std::unordered_map<char, string> map;
        std::unordered_set<string> used;
        std::stringstream ss(s);
        string word;
        int i = 0;
        while (std::getline(ss, word, ' ')) {
            if (!map.emplace(pattern[i], word).second) {
                if (map.at(pattern[i]) != word)
                    return false;
            }
            else if (!used.insert(word).second)
                return false;
            i++;
        }
        return i == pattern.size();
    }
};
