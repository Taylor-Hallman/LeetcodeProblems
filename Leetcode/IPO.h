#include <algorithm>
#include <climits>
#include <functional>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        int n = profits.size();
        std::map<int, std::priority_queue<int, std::vector<int>, std::greater<int>>, std::greater<int>> projects;
        for (int i = 0; i < n; i++) {
            if (projects.contains(profits[i]))
                projects[profits[i]].push(capital[i]);
            else {
                std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
                pq.push(capital[i]);
                projects[profits[i]] = pq;
            }
        }

        while (k > 0) {
            auto best = projects.end();
            for (auto itr = projects.begin(); itr != projects.end(); itr++) {
                if (itr->second.top() <= w) {
                    best = itr;
                    break;
                }
            }
            if (best == projects.end())
                break;
            w += best->first;
            best->second.pop();
            if (best->second.empty())
                projects.erase(best);
            k--;
        }
        return w;
    }
};