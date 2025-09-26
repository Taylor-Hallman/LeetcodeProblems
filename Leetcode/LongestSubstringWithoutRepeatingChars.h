#pragma once

#include <string>
#include <unordered_set>

using string = std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, best = 0;
        std::unordered_set<char> set;
        while (right < s.size()) {
            if (!set.insert(s[right]).second) {
                set.erase(s[left]);
                left++;
            }
            else right++;
            best = std::max(best, right - left);
        }
        return best;
    }
};