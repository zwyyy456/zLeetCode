// Created by zwyyy456 at 2023/07/18 09:52
// leetgo: 1.3.1
// https://leetcode.com/problems/sum-of-distances-in-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int count(vector<vector<int>> &tree, vector<int> &dis, vector<int> &cnt, int pa, int grandpa) {
        int res = 1;
        for (int child : tree[pa]) {
            if (child == grandpa) { // 防止重复遍历，保证 dfs 遍历时的单向性
                continue;
            }
            dis[child] = dis[pa] + 1;
            res += count(tree, dis, cnt, child, pa);
        }
        cnt[pa] = res;
        return res;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        vector<vector<int>> tree(n);
        for (auto &vec : edges) {
            tree[vec[0]].push_back(vec[1]);
            tree[vec[1]].push_back(vec[0]); // 注意，建立无向图要 push_back 两次！
        }
        vector<int> cnt(n);
        vector<int> dp(n);
        vector<int> dis(n); // 表示结点 0 到其他结点的最短距离
        count(tree, dis, cnt, 0, -1);
        for (int i = 0; i < n; ++i) {
            dp[0] += dis[i];
        }
        queue<pair<int, int>> q;
        q.push({0, -1}); // pa, grandpa
        while (!q.empty()) {
            auto [pa, grandpa] = q.front();
            q.pop();
            for (int child : tree[pa]) {
                if (child == grandpa) { // 保证 bfs 遍历时的单向性
                    continue;
                }
                dp[child] = dp[pa] + n - 2 * cnt[child];
                q.push({child, pa});
            }
        }
        return dp;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    vector<vector<int>> edges;
    LeetCodeIO::scan(cin, edges);

    Solution *obj = new Solution();

    auto res = obj->sumOfDistancesInTree(n, edges);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
