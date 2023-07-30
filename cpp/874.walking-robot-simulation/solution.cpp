// Created by zwyyy456 at 2023/07/20 14:31
// leetgo: 1.3.1
// https://leetcode.com/problems/walking-robot-simulation/

#include <bits/stdc++.h>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
        int direct = 0; // 0 表示向北
        int n = commands.size();
        unordered_set<long> ust;
        for (int i = 0; i < obstacles.size(); ++i) {
            ust.insert(obstacles[i][0] * 100000L + obstacles[i][1]);
        }
        int x = 0, y = 0;
        int prex = 0, prey = 0;
        int res = 0;
        vector<vector<int>> move{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        for (int i = 0; i < n; ++i) {
            if (commands[i] > 0) {
                for (int j = 0; j < commands[i]; ++j) {
                    prex = x;
                    prey = y;
                    x += move[(direct % 4 + 4) % 4][0];
                    y += move[(direct % 4 + 4) % 4][1];
                    if (ust.find(x * 100000L + y) != ust.end()) {
                        x = prex;
                        y = prey;
                        res = max(res, x * x + y * y);
                        break;
                    }
                    res = max(res, x * x + y * y);
                }
            } else {
                if (commands[i] == -1) {
                    direct -= 1;
                } else {
                    direct += 1;
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

    vector<int> commands;
    LeetCodeIO::scan(cin, commands);
    vector<vector<int>> obstacles;
    LeetCodeIO::scan(cin, obstacles);

    Solution *obj = new Solution();

    auto res = obj->robotSim(commands, obstacles);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
