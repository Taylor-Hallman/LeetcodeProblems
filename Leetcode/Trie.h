#pragma once

#include <iostream>
#include <unordered_map>

class Node {
private:
    std::unordered_map<char, Node*> children;
    bool isComplete;

    void clearChildren() {
        for (auto& kv : children) {
            delete kv.second;
        }
        children.clear();
    }

public:
    Node(bool b = false) : isComplete(b) {}

    // not strictly necessary but wanted to get some rule of 5 practice in
    ~Node() {
        for (auto itr = children.begin(); itr != children.end(); itr++) {
            delete itr->second;
        }
    }

    Node(const Node& other) : isComplete(other.isComplete) {
        for (auto itr = other.children.begin(); itr != other.children.end(); itr++) {
            children.insert(std::make_pair(itr->first, new Node(*itr->second)));
        }
    }

    Node& operator=(const Node& other) {
        isComplete = other.isComplete;
        clearChildren();
        for (auto itr = other.children.begin(); itr != other.children.end(); itr++) {
            children.insert(std::make_pair(itr->first, new Node(*itr->second)));
        }
        return *this;
    }

    Node(Node&& other) noexcept : children(std::move(other.children)), isComplete(other.isComplete) {}

    Node& operator=(Node&& other) noexcept {
        if (this != &other) {
            isComplete = other.isComplete;
            clearChildren();
            children = std::move(other.children);
        }
        return *this;
    }

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

class Trie {
    Node* root;

    Trie() {
        root = new Node();
    }

    ~Trie() {
        delete root;
    }

    Trie(const Trie& other) {
        root = new Node(*other.root);
    }

    Trie& operator=(const Trie& other) {
        if (this != &other) {
            delete root;
            root = new Node(*other.root);
        }
        return *this;
    }

    Trie(Trie&& other) noexcept {
        root = other.root;
        other.root = nullptr;
    }

    Trie& operator=(Trie&& other) noexcept {
        if (this != &other) {
            delete root;
            root = other.root;
            other.root = nullptr;
        }
        return *this;
    }

    void insert(std::string word) {
        Node* curNode = root;
        for (char c : word) {
            curNode = curNode->addOrGetChild(c);
        }
        curNode->markComplete();
    }

    bool search(std::string word) {
        Node* curNode = root;
        for (char c : word) {
            curNode = curNode->getChild(c);
            if (curNode == nullptr)
                return false;
        }
        return curNode->isCompleteWord();
    }

    bool startsWith(std::string prefix) {
        Node* curNode = root;
        for (char c : prefix) {
            curNode = curNode->getChild(c);
            if (curNode == nullptr)
                return false;
        }
        return true;
    }
};