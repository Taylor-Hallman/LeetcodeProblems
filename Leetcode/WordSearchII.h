#pragma once

#include <functional>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

class Solution {
    using string = std::string;

    struct Node {
        std::unordered_map<char, Node*> children;
        bool isComplete;
        Node(bool isComplete = false) : isComplete(isComplete) {}

        ~Node() {
            for (auto& [c, node] : children) {
                delete node;
            }
        }

        Node(const Node& other) : isComplete(other.isComplete) {
            for (auto& [c, node] : other.children) {
                children.emplace(c, new Node(node->isComplete));
            }
        }

        friend void swap(Node& n1, Node& n2) {
            std::swap(n1.isComplete, n2.isComplete);
            std::swap(n1.children, n2.children);
        }

        Node& operator=(Node other) {
            swap(*this, other);
            return *this;
        }

        void markComplete() { isComplete = true; }

        bool isCompleteWord() const { return isComplete; }

        Node* getChild(char c) const {
            if (children.contains(c))
                return children.at(c);
            return nullptr;
        }

        Node* getOrAddChild(char c) {
            Node* n = getChild(c);
            if (!n) {
                n = new Node();
                children.emplace(c, n);
            }
            return n;
        }
    };

    struct Trie {
        Node* root;
        Trie() : root(new Node()) {}

        ~Trie() { delete root; }

        Trie(const Trie& other) : root(other.root) {}

        Trie& operator=(Trie other) {
            std::swap(root, other.root);
            return *this;
        }

        void insert(string word) {
            Node* currNode = root;
            for (char c : word)
                currNode = currNode->getOrAddChild(c);
            currNode->markComplete();
        }
        
        bool contains(string word) const {
            Node* currNode = root;
            for (char c : word) {
                currNode = currNode->getChild(c);
                if (!currNode)
                    return false;
            }
            return currNode->isCompleteWord();
        }
    };

    struct HashFunction {
        size_t operator()(const std::pair<int, int>& p) const {
            return p.first ^ p.second;
        }
    };

    struct WordData {
        int x, y;
        Node* n;
        string word;
        std::unordered_set<std::pair<int, int>, HashFunction> visited;

        WordData(int x, int y, Node* node, string word) : x(x), y(y), n(node), word(word) {}
        WordData(int x, int y, Node* node, string word, std::unordered_set<std::pair<int, int>, HashFunction> visited)
            : x(x), y(y), n(node), word(word), visited(visited) {}
    };

public:
    std::vector<string> findWords(std::vector<std::vector<char>>& board, const std::vector<string>& words) {
        int m = board.size(), n = board[0].size();
        Trie trie;
        for (string word : words)
            trie.insert(word);
        std::unordered_set<string> foundWords;
        std::function<void(int, int, Node*, string&)> backtrack = [&](int x, int y, Node* node, string& word) {
            if (!node)
                return;
            if (node->isCompleteWord()) {
                foundWords.insert(word);
                node->isComplete = false;
            }
            if (x < 0 || x >= n || y < 0 || y >= m || board[y][x] == '\0')
                return;

            char c = board[y][x];
            board[y][x] = '\0';
            word += c;
            Node* child = node->getChild(c);
            static const int dirs[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0 , 1 } };
            for (auto& d : dirs) {
                backtrack(x + d[0], y + d[1], child, word);
            }
            board[y][x] = c;
            word.pop_back();
        };
        string path = "";
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++ ) {
                if (trie.root->children.contains(board[y][x]))
                    backtrack(x, y, trie.root, path);
            }
        }
        std::vector<string> foundWordsV(foundWords.begin(), foundWords.end());
        return foundWordsV;
    }
};
