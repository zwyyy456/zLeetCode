// Created by zwyyy456 at 2023/09/17 10:33
// leetgo: 1.3.5
// https://leetcode.cn/problems/maximum-number-of-alloys/
// https://leetcode.cn/contest/weekly-contest-363/problems/maximum-number-of-alloys/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool check(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, long mid, vector<int> &cost) {
        bool res = false;
        for (int i = 0; i < k; ++i) {
            vector<long> tmp(n);
            for (int j = 0; j < n; ++j) {
                tmp[j] = mid * composition[i][j];
            }
            int total = 0;
            for (int j = 0; j < n; ++j) {
                if (stock[j] < tmp[j]) {
                    total += (tmp[j] - stock[j]) * cost[j];
                }
            }
            res = res || (total <= budget);
        }
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost) {
        // n 种金属，k 台机器
        // 二分答案
        long l = 0, r = 1e8 + 1e8 + 200;
        // 左闭右开
        while (l < r) {
            long mid = l + (r - l) / 2;
            bool res = check(n, k, budget, composition, stock, mid, cost);
            if (res) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l - 1;
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
