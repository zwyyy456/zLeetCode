// Created by zwyyy456 at 2023/10/06 14:30
// leetgo: 1.3.8
// https://leetcode.com/problems/corporate-flight-bookings/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
        vector<int> ans(n);
        vector<int> diff(n + 2);
        for (int i = 0; i < bookings.size(); ++i) {
            int l = bookings[i][0], r = bookings[i][1], seats = bookings[i][2];
            diff[l] += seats;
            diff[r + 1] -= seats;
        }
        ans[0] = diff[0];
        int sum = diff[0];
        for (int i = 1; i < n; ++i) {
            sum += diff[i];
            ans[i] = sum;
        }
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> bookings;
    LeetCodeIO::scan(cin, bookings);
    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();
    auto res = obj->corpFlightBookings(bookings, n);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
