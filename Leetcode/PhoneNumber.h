#pragma once

#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    void backtrack(std::unordered_map<char, std::string> map, std::vector<std::string>& vec, std::string digits, std::string str, int idx) {
        if (idx >= digits.length()) {
            vec.push_back(str);
            return;
        }
        for (char c : map.at(digits[idx])) {
            backtrack(map, vec, digits, str + c, idx + 1);
        }
    }

    std::vector<std::string> letterCombinations(std::string digits) {
        std::unordered_map<char, std::string> map = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        std::vector<std::string> result;
        if (digits.length() > 0)
            backtrack(map, result, digits, "", 0);

        return result;
    }
};