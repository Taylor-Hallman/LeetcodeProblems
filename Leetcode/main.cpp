#include "SpiralMatrix.h"
#include <iostream>
#include <vector>

int main() {
	Solution s;
	std::vector<std::vector<int>> v = {
		{ { 23,18,20,26,25 } ,{ 24,22,3,4,4 }, { 15,22,2,24,29 }, { 18,15,23,28,28 } }
	};
	std::vector<int> ret = s.spiralOrder(v);
	for (int i = 0; i < ret.size(); i++) {
		std::cout << ret[i] << ", ";
	}
}