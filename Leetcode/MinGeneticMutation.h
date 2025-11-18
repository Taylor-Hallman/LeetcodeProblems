#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using string = std::string;

class Solution {
public:
    struct Node {
        string gene;
        int mutations;

        Node(string gene, int mutations) : gene(gene), mutations(mutations) {}
    };

    bool tryMutate(string& gene, int mutIdx, char mutChar, const std::unordered_set<string>& bank) {
        string newGene = gene;
        newGene[mutIdx] = mutChar;
        if (!bank.contains(newGene))
            return false;
        gene = newGene;
        return true;
    }

    int minMutation(string startGene, string endGene, std::vector<string>& bank) {
        int len = startGene.length();

        // convert bank to unordered set to make lookups easier
        std::unordered_set<string> bankSet;
        for (string gene : bank)
            bankSet.insert(gene);

        if (!bankSet.contains(endGene))
            return -1;

        auto cmp = [&endGene, &len](const Node& n1, const Node& n2) {
            int diffs1 = 0, diffs2 = 0;
            for (int i = 0; i < len; i++) {
                if (n1.gene[i] != endGene[i])
                    diffs1++;
                if (n2.gene[i] != endGene[i])
                    diffs2++;
            }
            return n1.mutations + diffs1 > n2.mutations + diffs2;
        };

        std::string alphab = "ACGT";

        std::priority_queue<Node, std::vector<Node>, decltype(cmp)> pq(cmp);
        std::unordered_set<string> genesTried;
        pq.push(Node(startGene, 0));
        while (!pq.empty()) {
            auto [gene, mutations] = pq.top();
            pq.pop();
            if (!genesTried.insert(gene).second)
                continue;
            if (gene == endGene)
                return mutations;

            for (int i = 0; i < len; i++) {
                for (char c : alphab) {
                    if (gene[i] == c)
                        continue;
                    std::string newGene = gene;
                    if (tryMutate(newGene, i, c, bankSet))
                        pq.push(Node(newGene, mutations + 1));
                }
            }
        }
        return -1;
    }
};