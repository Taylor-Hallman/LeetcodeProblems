#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <iostream>

class Node {
public:
    Node() : c('\0') {}

    Node(char _c) : c(_c) {}

    void AddChild(Node* child) {
        children.push_back(child);
    }

    bool hasChildren() { return !children.empty(); }

    std::vector<Node*> getChildren() { return children; }

    char getChar() { return c; }

private:
    std::vector<Node*> children;
    char c;
};

class Solution {
public:
    /*std::vector<std::string> letterCombinations(std::string digits) {
        std::string mappings[9] = {
            "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        Node* root = new Node();
        std::vector<Node*> prev, curr;
        prev.push_back(root);
        
        for (char digit : digits) {
            for (char c : mappings[digit - '0' - 1]) {
                Node* n = new Node(c);
                for (Node* n2 : prev) {
                    n2->AddChild(n);
                }
                curr.push_back(n);
            }
            prev = curr;
            curr.clear();
        }

        std::stack<std::pair<Node*, std::string>> s;
        s.push(std::make_pair(root, ""));

        std::vector<std::string> result;

        while (!s.empty()) {
            auto pair = s.top();
            s.pop();

            std::string str = pair.second + pair.first->getChar();

            if (!pair.first->hasChildren()) {
                result.push_back(str);
                continue;
            }

            for (auto& child : pair.first->getChildren()) {
                s.push(std::make_pair(child, str));
            }
        }

        return result;
    }*/

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