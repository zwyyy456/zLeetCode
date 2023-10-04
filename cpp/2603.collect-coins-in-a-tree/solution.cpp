// Created by zwyyy456 at 2023/09/21 19:45
// leetgo: 1.3.8
// https://leetcode.com/problems/collect-coins-in-a-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges) {
        int n = coins.size();
        vector<vector<int>> graph(n);
        vector<int> degree(n);
        for (auto &vec : edges) {
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
            ++degree[vec[0]];
            ++degree[vec[1]];
        }
        // 第一次拓扑排序，去除那些没有金币的叶子结点，以及没有金币的衍生的叶子结点
        // 叶子结点的度为 1
        queue<int> topo1;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1 && coins[i] == 0) {
                topo1.push(i);
            }
        }
        int cnt = 0;
        while (!topo1.empty()) {
            int idx = topo1.front();
            topo1.pop();
            ++cnt;
            for (int next : graph[idx]) {
                if (--degree[next] == 1 && coins[idx] == 0) {
                    topo1.push(next);
                }
            }
        }
        // 现在我们判断那些有金币的叶子结点，可以不用去，因此删掉
        // 再判断一次剩下的叶子结点，
        queue<int> topo2;
        int times = 0;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1 && coins[i] == 0) {
                topo2.push(i);
            }
        }
        while (times < 2) {
            int sz = topo2.size();
            for (int i = 0; i < sz; ++i) {
                auto idx = topo2.front();
                topo2.pop();
                ++cnt;
                for (int next : graph[idx]) {
                    if (--degree[next] == 1 && coins[idx] == 0) {
                        topo1.push(next);
                    }
                }
            }
        }
        return max(0, 2 * (n - cnt));
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> coins;
    LeetCodeIO::scan(cin, coins);
    vector<vector<int>> edges;
    LeetCodeIO::scan(cin, edges);

    Solution *obj = new Solution();
    auto res = obj->collectTheCoins(coins, edges);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
