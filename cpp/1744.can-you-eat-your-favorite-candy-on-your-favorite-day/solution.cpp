// Created by zwyyy456 at 2023/10/13 10:57
// leetgo: 1.3.8
// https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries) {
        int n = queries.size();
        vector<int> ids(n);
        for (int i = 0; i < n; ++i) {
            ids[i] = i;
        }
        auto cmp = [&queries](int i, int j) {
            return queries[i][1] < queries[j][1];
        };
        vector<int> prefix(candiesCount.size() + 1);
        for (int i = 1; i <= candiesCount.size(); ++i) {
            prefix[i] = prefix[i - 1] + candiesCount[i - 1];
        }
        sort(ids.begin(), ids.end(), cmp);
        for (int i = 0; i < n; ++i) {
        }
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> candiesCount;
    LeetCodeIO::scan(cin, candiesCount);
    vector<vector<int>> queries;
    LeetCodeIO::scan(cin, queries);

    Solution *obj = new Solution();
    auto res = obj->canEat(candiesCount, queries);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
