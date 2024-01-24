// Created by zwyyy456 at 2024/01/24 10:59
// leetgo: 1.3.8
// https://leetcode.com/problems/beautiful-towers-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    using i64 = long long;
    long long maximumSumOfHeights(vector<int> &maxHeights) {
        // sum[i] 表示以 i 为山峰的高度和的最大值
        int n = maxHeights.size();
        i64 res = 0;
        for (int i = 0; i < n; ++i) {
            i64 tmp_sum = maxHeights[i];
            int tmp = maxHeights[i];
            for (int l = i - 1; l >= 0; --l) {
                tmp = min(tmp, maxHeights[l]);
                tmp_sum += tmp;
            }
            tmp = maxHeights[i];
            for (int r = i + 1; r < n; ++r) {
                tmp = min(tmp, maxHeights[r]);
                tmp_sum += tmp;
            }
            res = max(res, tmp_sum);
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> maxHeights;
    LeetCodeIO::scan(cin, maxHeights);

    Solution *obj = new Solution();
    auto res = obj->maximumSumOfHeights(maxHeights);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
