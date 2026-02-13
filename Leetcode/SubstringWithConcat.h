#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
    using string = std::string;

public:
    std::vector<int> findSubstring(string s, std::vector<string>& words) {
        int wordLen = words[0].size();
        if (wordLen > s.size())
            return {};
        std::unordered_map<string, int> origMap;

        for (string word : words)
            origMap[word]++;

        std::vector<int> result;
        for (int i = 0; i < wordLen; i++) {
            std::unordered_map<string, int> sMap;
            for (string word : words)
                sMap[word] = 0;
            int totalWords = 0;
            int left = i, right = i;
            while (right <= (s.size() - wordLen) || totalWords == words.size()) {
                string rWord = s.substr(right, wordLen), lWord = s.substr(left, wordLen);
                if (totalWords == words.size()) {
                    result.push_back(left);
                    left += wordLen;
                    sMap[lWord]--;
                    totalWords--;
                }
                else if (!origMap.contains(rWord)) {
                    right += wordLen;
                    left = right;
                    totalWords = 0;
                    for (string word : words)
                        sMap[word] = 0;
                }
                else if (sMap.at(rWord) == origMap.at(rWord)) {
                    sMap[lWord]--;
                    left += wordLen;
                    totalWords--;
                }
                else {
                    sMap[rWord]++;
                    right += wordLen;
                    totalWords++;
                }
            }
            if (totalWords == words.size())
                result.push_back(left);
        }
        return result;
    }
};
