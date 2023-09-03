// Created by zwyyy456 at 2023/08/23 09:20
// leetgo: 1.3.5
// https://leetcode.com/problems/guess-number-higher-or-lower-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int dfs(int l, int r, vector<vector<int>> &cache) {
        int cost = 0;
        if (l >= r) {
            return 0;
        }
        if (cache[l][r] >= 0) {
            return cache[l][r];
        }
        for (int i = l; i < r; ++i) {
            cost = min(cost, i + max(dfs(l, i, cache), dfs(i + 1, r, cache)));
        }
        cache[l][r] = cost;
        return cost;
    }
    int getMoneyAmount(int n) {
        // 最大值的最小值
        // 选一种策略，这个策略的最大开销是最小的
    	vector<vector<int>> cache(n + 2, vector<int>(n + 2, -1));
    	return dfs(1, n + 1, cache);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();
    auto res = obj->getMoneyAmount(n);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
