#include "MergeIntervals.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
	Solution s;
	std::vector<std::vector<int>> vec = { {4, 6}, {2, 2}, {4, 6}, {5, 6}, {0, 0}, {5, 5}, {1, 1}, {1, 1}, {4, 4}, {4, 5}, {3, 3}, {5, 5} };
	auto v = s.merge(vec);
	for (auto& interval : v) {
		std::cout << std::to_string(interval[0]) + ", " + std::to_string(interval[1]) << std::endl;
	}
}