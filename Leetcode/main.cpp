#include "SurroundedRegions.h"
#include <iostream>

int main() {
	std::vector<std::vector<char>> board = {{'X', 'X', 'X'}, {'X', 'O', 'X'}, {'X', 'X', 'X'}};
	Solution s;
	s.solve(board);
	int m = board[0].size(), n = board.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << board[i][j];
			if (j < m - 1) std::cout << ", ";
		}
		std::cout << std::endl;
	}
	std::cin.get();
}