// Created by zwyyy456 at 2023/08/29 11:41
// leetgo: 1.3.5
// https://leetcode.com/problems/binary-trees-with-factors/

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int numFactoredBinaryTrees(vector<int> &arr) {
        const int mod = 1e9 + 7;
        using ust = unordered_set<int>;
        using ump = unordered_map<int, int>;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<ust> vecs(n);
        ump nums;
        for (int i = 0; i < n; ++i) {
            nums[arr[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int k = arr[i] / arr[j];
                if (k * arr[j] != arr[i]) {
                    continue;
                }
                if (nums.find(k) == nums.end()) {
                    continue;
                }
                vecs[i].insert(arr[j]);
                vecs[i].insert(k);
            }
        }
        // 动态规划
        // dp[i] = 1 + sum(dp[j] * dp[i / j] (此时 i != j) + dp[j] * (dp[j] + 1) / 2 （此时 j * j = i）
        vector<int> dp(n, 1);
        int res = 1;
        for (int i = 1; i < n; ++i) {
            int num = arr[i];
            while (!vecs[i].empty()) {
                int fac1 = *vecs[i].begin();
                int fac2 = num / fac1;
                vecs[i].erase(fac1);
                if (fac2 == fac1) {
                    int idx = nums[fac1];
                    dp[i] = (dp[i] + dp[idx] * dp[idx]) % mod;
                } else {
                    dp[i] = (dp[i] + 2 * (dp[nums[fac1]] * dp[nums[fac2]]) % mod;
                    vecs[i].erase(fac2);
                }
            }
            res = (res + dp[i]) % mod;
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> arr;
    LeetCodeIO::scan(cin, arr);

    Solution *obj = new Solution();
    auto res = obj->numFactoredBinaryTrees(arr);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
