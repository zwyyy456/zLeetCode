// Created by zwyyy456 at 2023/10/06 12:09
// leetgo: 1.3.8
// https://leetcode.com/problems/car-pooling/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        const int right = 1001;
        int n = trips.size();
        vector<int> diff(right);
        for (int i = 0; i < n; ++i) {
            int cnt = trips[i][0], l = trips[i][1], r = trips[i][2];
            diff[l] += cnt;
            if (r + 1 < right) {
                diff[r + 1] -= cnt;
            }
        }
        if (diff[0] > capacity) {
            return false;
        }
        int sum = diff[0];
        for (int i = 1; i < right; ++i) {
            sum += diff[i];
            if (sum > capacity) {
                return false;
            }
        }
        return true;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> trips;
    LeetCodeIO::scan(cin, trips);
    int capacity;
    LeetCodeIO::scan(cin, capacity);

    Solution *obj = new Solution();
    auto res = obj->carPooling(trips, capacity);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
