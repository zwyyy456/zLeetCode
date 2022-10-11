/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  private:
    bool isValid(int row, int col, char val, vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) { // 判断行里是否重复
            if (board[row][i] == val) {
                return false;
            }
        }
        for (int j = 0; j < 9; j++) { // 判断列里是否重复
            if (board[j][col] == val) {
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
    bool track_back(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {     // 逐行
            for (int j = 0; j < 9; j++) { // 逐列
                if (board[i][j] != '.')
                    continue;
                for (char k = '1'; k <= '9'; k++) {
                    if (isValid(i, j, k, board)) {
                        board[i][j] = k;
                        if (track_back(board))
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

  public:
    void solveSudoku(vector<vector<char>> &board) {
        track_back(board);
    }
};
// @lc code=end
