#pragma once

#include "GraphNode.h"
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        std::unordered_map<int, Node*> newNodes;
        std::stack<Node*> s;
        s.push(node);
        while (!s.empty()) {
            Node* node = s.top();
            s.pop();
            Node* copy;
            if (newNodes.contains(node->val)) {
                copy = newNodes.at(node->val);
                if (copy->neighbors.size() == node->neighbors.size())
                    continue;
            }
            else {
                copy = new Node(node->val);
                newNodes[node->val] = copy;
            }
            for (Node* neighbor : node->neighbors) {
                auto itr = newNodes.find(neighbor->val);
                Node* neighborCopy;
                if (itr != newNodes.end()) {
                    neighborCopy = itr->second;
                    if (std::find(copy->neighbors.begin(), copy->neighbors.end(), neighborCopy) == copy->neighbors.end()) {
                        copy->neighbors.push_back(neighborCopy);
                        neighborCopy->neighbors.push_back(copy);
                    }
                }
                else {
                    neighborCopy = new Node(neighbor->val);
                    newNodes[neighbor->val] = neighborCopy;
                    copy->neighbors.push_back(neighborCopy);
                    neighborCopy->neighbors.push_back(copy);
                }
                if (neighborCopy->neighbors.size() < neighbor->neighbors.size())
                    s.push(neighbor);
            }
        }
        return newNodes.at(node->val);
    }
};
