#pragma once

#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
public:

    void markRegion(std::vector<std::vector<char>>& board, int row, int col) {
        int m = board.size(), n = board[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'O')
            return;
        board[row][col] = '*';
        markRegion(board, row + 1, col);
        markRegion(board, row - 1, col);
        markRegion(board, row, col + 1);
        markRegion(board, row, col - 1);
    }

    void solve(std::vector<std::vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for (int row = 0; row < m; row++) {
            if (board[row][0] == 'O')
                markRegion(board, row, 0);
            if (board[row][n - 1] == 'O')
                markRegion(board, row, n - 1);
        }
        for (int col = 1; col < n - 1; col++) {
            if (board[0][col] == 'O')
                markRegion(board, 0, col);
            if (board[m - 1][col] == 'O')
                markRegion(board, m - 1, col);
        }

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                char& c = board[row][col];
                if (c == '*')
                    c = 'O';
                else if (c == 'O')
                    c = 'X';
            }
        }
    }
};