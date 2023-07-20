// Created by zwyyy456 at 2023/07/20 14:54
// leetgo: 1.3.1
// https://leetcode.com/problems/queens-that-can-attack-the-king/

#include <bits/stdc++.h>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king) {
        int n = queens.size();
        vector<vector<int>> res;
        // 从国王的角度进行判断，八个方向
        unordered_set<int> ust;
        for (int i = 0; i < n; ++i) {
            ust.insert(queens[i][0] * 10 + queens[i][1]);
        }
        for (int i = king[0]; i >= 0; --i) {
            if (ust.find(i * 10 + king[1]) != ust.end()) {
                res.push_back({i, king[1]});
                break;
            }
        }
        for (int i = king[0]; i < 8; ++i) {
            if (ust.find(i * 10 + king[1]) != ust.end()) {
                res.push_back({i, king[1]});
                break;
            }
        }
        for (int i = king[1]; i >= 0; --i) {
            if (ust.find(king[0] * 10 + i) != ust.end()) {
                res.push_back({king[0], i});
                break;
            }
        }
        for (int i = king[1]; i < 8; ++i) {
            if (ust.find(king[0] * 10 + i) != ust.end()) {
                res.push_back({king[0], i});
                break;
            }
        }
        for (int i = king[0], j = king[1]; i < 8 && j < 8; ++i, ++j) {
            if (ust.find(i * 10 + j) != ust.end()) {
                res.push_back({i, j});
                break;
            }
        }
        for (int i = king[0], j = king[1]; i >= 0 && j >= 0; --i, --j) {
            if (ust.find(i * 10 + j) != ust.end()) {
                res.push_back({i, j});
                break;
            }
        }
        for (int i = king[0], j = king[1]; i >= 0 && j < 8; --i, ++j) {
            if (ust.find(i * 10 + j) != ust.end()) {
                res.push_back({i, j});
                break;
            }
        }
        for (int i = king[0], j = king[1]; i < 8 && j >= 0; ++i, --j) {
            if (ust.find(i * 10 + j) != ust.end()) {
                res.push_back({i, j});
                break;
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> queens;
    LeetCodeIO::scan(cin, queens);
    vector<int> king;
    LeetCodeIO::scan(cin, king);

    Solution *obj = new Solution();

    auto res = obj->queensAttacktheKing(queens, king);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
