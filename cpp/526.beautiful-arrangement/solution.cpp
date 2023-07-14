// Created by zwyyy456 at 2023/07/08 23:15
// leetgo: 1.3.2
// https://leetcode.com/problems/beautiful-arrangement/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool check(int i, int idx) {
        return i % idx == 0 || idx % i == 0;
    }
    int dfs(int idx, int choose, int n, vector<vector<int>> &cach) {
        if (idx > n) {
            return 1;
        }
        if (cach[idx][choose] != -1) {
            return cach[idx][choose];
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if ((choose & (1 << (i - 1))) == 0 && check(i, idx)) {
                res += dfs(idx + 1, choose | (1 << (i - 1)), n, cach);
            }
        }
        cach[idx][choose] = res;
        return res;
    }
    int countArrangement(int n) {
        int idx = 1, choose = 0;
        vector<vector<int>> cach(n + 1, vector<int>(1 << n, -1));
        int res = dfs(idx, choose, n, cach);
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();

    auto res = obj->countArrangement(n);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
