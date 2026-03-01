#pragma once

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <set>

class Solution {
    using string = std::string;
public:
    int ladderLength(string beginWord, string endWord, const std::vector<string>& wordList) {
        std::unordered_set<string> wordSet;
        std::set<char> alphab;
        for (string word : wordList) {
            wordSet.insert(word);
            for (char c : word)
                alphab.insert(c);
        }
        if (!wordSet.contains(endWord))
            return 0;
        std::queue<std::pair<string, int>> q;
        std::unordered_set<string> visited;
        q.emplace(beginWord, 1);
        while (!q.empty()) {
            auto [word, steps]= q.front();
            q.pop();
            if (!visited.insert(word).second)
                continue;
            if (word == endWord)
                return steps;
            for (int i = 0; i < word.length(); i++) {
                for (char c : alphab) {
                    if (word[i] == c)
                        continue;
                    string newWord = word;
                    newWord[i] = c;
                    if (wordSet.contains(newWord))
                        q.emplace(newWord, steps + 1);
                }
            }
        }
        return 0;
    }
};
