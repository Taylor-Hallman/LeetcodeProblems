#include "Combinations.h"
#include <iostream>

int main() {
	Solution s;
	auto result = s.combine(5, 3);
	for (std::vector<int> v : result) {
		std::cout << "[ ";
		for (int n : v)
			std::cout << n << " ";
		std::cout << "]\n";
	}
}