// Created by zwyyy456 at 2023/12/06 15:36
// leetgo: 1.3.8
// https://leetcode.com/problems/minimize-the-total-price-of-the-trips/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips) {
    		
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
    vector<int> price;
    LeetCodeIO::scan(cin, price);
    vector<vector<int>> trips;
    LeetCodeIO::scan(cin, trips);

    Solution *obj = new Solution();
    auto res = obj->minimumTotalPrice(n, edges, price, trips);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
