// Created by zwyyy456 at 2023/09/07 21:27
// leetgo: 1.3.5
// https://leetcode.com/problems/minimum-time-to-repair-cars/

#include <bits/stdc++.h>
#include <cmath>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool check(long mid, vector<int> &ranks, long cars) {
        long total = 0;
        for (int a : ranks) {
            long x = sqrt(double(mid) / a);
            total += x;
        }
        return total >= cars;
    }
    long long repairCars(vector<int> &ranks, int cars) {
        // 最小化最大值，二分
        long r = 1e12 + 1;
        long l = 1; // 左闭右开
        int n = ranks.size();
        while (l < r) {
            long mid = l + (r - l) / 2;
            if (!check(mid, ranks, cars)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> ranks;
    LeetCodeIO::scan(cin, ranks);
    int cars;
    LeetCodeIO::scan(cin, cars);

    Solution *obj = new Solution();
    auto res = obj->repairCars(ranks, cars);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
