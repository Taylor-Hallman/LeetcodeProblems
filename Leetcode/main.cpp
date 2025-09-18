#include "Triangle.h"
#include <iostream>
#include <vector>

int main() {
	Solution s;
	std::vector<std::vector<int>> vec = {
		{ 2 },
		{ 3, 4 },
		{ 6, 5, 7 },
		{ 4, 1, 8, 3 }
	};
	std::cout << s.minimumTotal(vec) << std::endl;
}