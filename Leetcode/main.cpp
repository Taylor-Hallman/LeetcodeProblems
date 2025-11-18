#include "MinGeneticMutation.h"
#include <iostream>

int main() {
	Solution s;
	std::vector<string> bank = { "AACCGATT","AACCGATA","AAACGATA","AAACGGTA" };
	int result = s.minMutation("AACCGGTT", "AAACGGTA", bank);
	std::cout << result << std::endl;
	std::cin.get();
}