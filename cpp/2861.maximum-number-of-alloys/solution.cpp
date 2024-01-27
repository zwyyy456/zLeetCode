// Created by zwyyy456 at 2024/01/27 17:03
// leetgo: 1.3.8
// https://leetcode.com/problems/maximum-number-of-alloys/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool check(long mid, vector<int> &compose, vector<int> &stock, vector<int> &cost, long budget) {
        long sum = 0;
        for (int i = 0; i < compose.size(); ++i) {
            if (mid * compose[i] > (long)stock[i]) {
                sum += (mid * compose[i] - (long)stock[i]) * cost[i];
            }
        }
        return sum <= budget;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost) {
        // 选择哪个机器来制造合金？
        int res = 0;
        for (int i = 0; i < k; ++i) {
            int l = 0, r = 1e9 + 1;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (check(mid, composition[i], stock, cost, budget)) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            res = max(res, l - 1);
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    int k;
    LeetCodeIO::scan(cin, k);
    int budget;
    LeetCodeIO::scan(cin, budget);
    vector<vector<int>> composition;
    LeetCodeIO::scan(cin, composition);
    vector<int> stock;
    LeetCodeIO::scan(cin, stock);
    vector<int> cost;
    LeetCodeIO::scan(cin, cost);

    Solution *obj = new Solution();
    auto res = obj->maxNumberOfAlloys(n, k, budget, composition, stock, cost);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
