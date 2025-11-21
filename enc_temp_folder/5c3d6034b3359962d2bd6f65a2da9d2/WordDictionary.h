#pragma once

#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using string = std::string;

class WordDictionary {
private:
    class Node {
    private:
        bool isComplete;
    public:
        std::unordered_map<char, Node*> children;
        Node(bool b = false) : isComplete(b) {}

        Node* getChild(char c) {
            if (children.contains(c))
                return children.at(c);
            return nullptr;
        }

        Node* addOrGetChild(char c) {
            Node* child = getChild(c);
            if (child == nullptr)
                child = children.insert(std::make_pair(c, new Node())).first->second;
            return child;
        }

        void markComplete() { isComplete = true; }

        bool isCompleteWord() const { return isComplete; }

        bool contains(char c) const {
            return children.contains(c);
        }
    };

    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* curNode = root;
        for (char c : word) {
            curNode = curNode->addOrGetChild(c);
        }
        curNode->markComplete();
    }

    bool search(string word) {
        std::stack<std::pair<Node*, int>> s;
        s.push(std::make_pair(root, 0));

        while (!s.empty()) {
            auto [node, idx] = s.top();
            s.pop();

            if (idx == word.size() && node->isCompleteWord())
                return true;

            if (word[idx] == '.') {
                for (auto [c, n] : node->children)
                    s.push(std::make_pair(n, idx + 1));
            }
            else if (Node* n = node->getChild(word[idx]))
                s.push(std::make_pair(n, idx + 1));
        }
        return false;
    }
};