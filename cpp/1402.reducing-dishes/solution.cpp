// Created by zwyyy456 at 2023/10/22 16:54
// leetgo: 1.3.8
// https://leetcode.com/problems/reducing-dishes/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxSatisfaction(vector<int> &satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        if (satisfaction.back() <= 0) {
            return 0;
        }
        int sum = satisfaction.back(), cnt = 1;
        for (int i = n - 2; i >= 0; --i) {
            if (sum + satisfaction[i] < 0) {
                break;
            }
            sum += satisfaction[i];
            ++cnt;
        }
        int res = 0;
        for (int i = 0; i < cnt; ++i) {
            res += satisfaction[n - 1 - i] * (cnt - i);
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> satisfaction;
    LeetCodeIO::scan(cin, satisfaction);

    Solution *obj = new Solution();
    auto res = obj->maxSatisfaction(satisfaction);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
