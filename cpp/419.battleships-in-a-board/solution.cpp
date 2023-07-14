// Created by zwyyy456 at 2023/07/11 23:21
// leetgo: 1.3.2
// https://leetcode.com/problems/battleships-in-a-board/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    void dfs(int x, int y, vector<vector<char>> &board, vector<vector<int>> &vis, vector<vector<int>> &move) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < 4; ++i) {
            int new_x = x + move[i][0], new_y = y + move[i][1];
            if (new_x < m && new_x >= 0 && new_y < n && new_y >= 0 && board[new_x][new_y] == 'X' && vis[new_x][new_y] == 0) {
                vis[new_x][new_y] = 1;
                dfs(new_x, new_y, board, vis, move);
            }
        }
    }
    int countBattleships(vector<vector<char>> &board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        int res = 0;
        vector<vector<int>> move{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && board[i][j] == 'X') {
                    res += 1;
                    vis[i][j] = 1;
                    dfs(i, j, board, vis, move);
                }
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<char>> board;
    LeetCodeIO::scan(cin, board);

    Solution *obj = new Solution();

    auto res = obj->countBattleships(board);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
