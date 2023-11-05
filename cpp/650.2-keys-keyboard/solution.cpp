// Created by zwyyy456 at 2023/10/27 15:14
// leetgo: 1.3.8
// https://leetcode.com/problems/2-keys-keyboard/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int dfs(int n, vector<int> &cach) {
        if (cach[n] != 0) {
            return cach[n];
        }
        int tmp = 1e5 + 1;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                tmp = min(tmp, dfs(i, cach) + n / i);
            }
        }
        cach[n] = tmp;
        return tmp;
    }
    int minSteps(int n) {
        vector<int> cach(n + 1);
        cach[1] = 0;
        return dfs(n, cach);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();
    auto res = obj->minSteps(n);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
