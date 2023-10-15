// Created by zwyyy456 at 2023/10/06 15:44
// leetgo: 1.3.8
// https://leetcode.com/problems/maximize-the-minimum-powered-city/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool check(int mid, vector<int> &cap, int k, int r) {
        int n = cap.size();
        vector<int> diff(n);
        diff[0] = cap[0];
        for (int i = 1; i < n; ++i) {
            diff[i] = cap[i] - cap[i - 1];
        }
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            sum += diff[i];
            if (sum < mid) {
                k -= mid - sum;
                if (k < 0) {
                    return false;
                }
                diff[i] += mid - sum;
                if (i + 2 * r + 1 < n) {
                    diff[i + 2 * r + 1] -= mid - sum;
                }
            }
        }
        return k >= 0;
    }
    long bfind(long l, long r, vector<int> &cap, int k, int round) {
        while (l < r) {
            long mid = l + (r - l) / 2;
            if (check(mid, cap, k, round)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l - 1;
    }
    long long maxPower(vector<int> &stations, int r, int k) {
        // 先通过前缀和求出初始的供电数目
        int n = stations.size();
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + stations[i - 1];
        }
        vector<int> cap(n);
        for (int i = 0; i < n; ++i) {
            if (i + r >= n) {
                if (i - r < 0) {
                    cap[i] = prefix[n];
                } else {
                    cap[i] = prefix[n] - prefix[i - r];
                }
            } else {
                if (i - r < 0) {
                    cap[i] = prefix[i + r + 1];
                } else {
                    cap[i] = prefix[i + r + 1] - prefix[i - r];
                }
            }
        }
        return bfind(0, 2e10, cap, k, r);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> stations;
    LeetCodeIO::scan(cin, stations);
    int r;
    LeetCodeIO::scan(cin, r);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();
    auto res = obj->maxPower(stations, r, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
