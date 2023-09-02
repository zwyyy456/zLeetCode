// Created by zwyyy456 at 2023/08/22 09:08
// leetgo: 1.3.5
// https://leetcode.com/problems/maximize-distance-to-closest-person/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxDistToClosest(vector<int> &seats) {
        int distance = 0, n = seats.size();
        int cnt = 0;
        int left = 0, right = 0;
        int i = 0;
        while (i < n) {
            if (seats[i] == 1) {
                left = right;
                right = i;
                distance = max(distance, i - 1);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                left = right;
                right = i;
                distance = max((right - left - 2) / 2, distance);
            }
        }
        distance = max(n - 1 - right - 1, distance);
        return distance;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> seats;
    LeetCodeIO::scan(cin, seats);

    Solution *obj = new Solution();
    auto res = obj->maxDistToClosest(seats);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
