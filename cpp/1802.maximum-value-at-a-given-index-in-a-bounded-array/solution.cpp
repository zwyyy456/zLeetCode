// Created by zwyyy456 at 2023/11/10 22:18
// leetgo: 1.3.8
// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool check(int mid, int llen, int rrlen, long long maxsum) {
        long long lsum = 0, rsum = 0;
        if (llen >= mid - 1) {
            lsum += (mid + 1) * mid / 2 + llen - (mid - 1);
        } else {
            lsum += (mid - llen + mid) * (llen + 1) / 2;
        }
        if (rrlen >= mid - 1) {
            rsum += (mid) * (mid - 1) / 2 + rrlen - (mid - 1);
        } else {
            rsum += (mid - 1 + mid - rrlen) * rrlen / 2;
        }
        return lsum + rsum <= maxsum;
    }
    int maxValue(int n, int index, int maxSum) {
        int llen = index, rlen = n - index - 1;
        // 二分
        int l = 1, r = maxSum + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(mid, llen, rlen, maxSum)) {
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
    int index;
    LeetCodeIO::scan(cin, index);
    int maxSum;
    LeetCodeIO::scan(cin, maxSum);

    Solution *obj = new Solution();
    auto res = obj->maxValue(n, index, maxSum);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
