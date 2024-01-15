// Created by zwyyy456 at 2023/12/11 15:45
// leetgo: 1.3.8
// https://leetcode.com/problems/path-with-minimum-effort/

#include <bits/stdc++.h>
#include <utility>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool check(int mid, vector<vector<int>> &heights, vector<vector<int>> &move) {
        int m = heights.size(), n = heights[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vis[0][0] = 1;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto [x, y] = q.front();
            if (x == m - 1 && y == n - 1) {
                return true;
            }
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int newx = x + move[i][0], newy = y + move[i][1];
                if (newx >= 0 && newx < m && newy >= 0 && newy < n && vis[newx][newy] == 0 && abs(heights[x][y] - heights[newx][newy]) <= mid) {
                    vis[newx][newy] = 1;
                    q.emplace(newx, newy);
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>> &heights) {
        // binary search the answer
        int l = 0, r = 1e6 + 1;
        vector<vector<int>> move{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (!check(mid, heights, move)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> heights;
    LeetCodeIO::scan(cin, heights);

    Solution *obj = new Solution();
    auto res = obj->minimumEffortPath(heights);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
