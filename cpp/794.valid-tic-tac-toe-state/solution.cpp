// Created by zwyyy456 at 2023/07/25 09:00
// leetgo: 1.3.1
// https://leetcode.com/problems/valid-tic-tac-toe-state/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool check(vector<string> &board, char c) {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == c && board[i][1] == c && board[i][2] == c) {
                return true;
            }
            if (board[0][i] == c && board[1][i] == c && board[2][i] == c) {
                return true;
            }
            if (board[i][i] == c) {
                ++cnt1;
            }
            if (board[i][2 - i] == c) {
                ++cnt2;
            }
        }
        return cnt1 == 3 || cnt2 == 3;
    }
    bool validTicTacToe(vector<string> &board) {
        int cnt[2] = {0};
        for (auto &str : board) {
            for (char c : str) {
                if (c == 'X') {
                    ++cnt[0];
                } else if (c == 'O') {
                    ++cnt[1];
                }
            }
        }
        if (cnt[0] - cnt[1] >= 2 || cnt[0] < cnt[1]) {
            return false;
        }
        if (check(board, 'X') && check(board, 'O')) {
            return false;
        }
        if (check(board, 'X') && cnt[0] <= cnt[1]) {
            return false;
        }
        if (check(board, 'O') && cnt[0] > cnt[1]) {
            return false;
        }
        return true;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> board;
    LeetCodeIO::scan(cin, board);

    Solution *obj = new Solution();

    auto res = obj->validTicTacToe(board);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
