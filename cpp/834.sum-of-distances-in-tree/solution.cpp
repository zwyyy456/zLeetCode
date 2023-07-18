// Created by zwyyy456 at 2023/07/17 23:02
// leetgo: 1.3.2
// https://leetcode.com/problems/sum-of-distances-in-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int count(vector<vector<int>> &tree, vector<int> &dis, vector<int> &cnt, int pa) {
        int res = 1;
        for (int child : tree[pa]) {
            dis[child] = dis[pa] + 1;
            res += count(tree, dis, cnt, child);
        }
        cnt[pa] = res;
        return cnt[pa];
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        vector<vector<int>> tree(n);
        vector<int> is_pa(n, 1);
        for (auto &vec : edges) {
            tree[vec[0]].push_back(vec[1]);
            is_pa[vec[1]] = 0;
        }
        int pa = -1;
        for (int i = 0; i < n; ++i) {
            if (is_pa[i] == 1) { // 只会有一个 pa
                pa = i;
            }
        }
        vector<int> dp(n);
        vector<int> dis(n, 0);
        vector<int> cnt(n);
        count(tree, dis, cnt, pa);
        for (int i = 0; i < n; ++i) {
            dp[pa] += dis[i];
        }
        queue<int> q;
        q.push(pa);
        while (!q.empty()) {
            int fa = q.front();
            q.pop();
            for (int child : tree[fa]) {
                dp[child] = dp[fa] + cnt[pa] - 2 * cnt[child];
                q.push(fa);
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
