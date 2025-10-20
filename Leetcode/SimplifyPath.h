#pragma once

#include <string>
#include <vector>
#include <sstream>

using string = std::string;

class Solution {
public:
    string simplifyPath(string path) {
        std::vector<string> directories;
        string token;
        std::istringstream stream(path);
        while (std::getline(stream, token, '/')) {
            if (token == "." || token == "")
                continue;
            if (token == "..") {
                if (directories.empty())
                    break;
                directories.pop_back();
                continue;
            }
            directories.push_back(token);
        }

        string simplified = "";
        for (const string& dir : directories)
            simplified += ("/" + dir);

        return simplified;
    }
};