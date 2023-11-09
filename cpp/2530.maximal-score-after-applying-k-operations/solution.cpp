// Created by zwyyy456 at 2023/10/18 09:22
// leetgo: 1.3.8
// https://leetcode.com/problems/maximal-score-after-applying-k-operations/

#include <bits/stdc++.h>
#include <queue>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    long long maxKelements(vector<int> &nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long res = 0;
        for (int i = 0; i < k; ++i) {
            int tmp = pq.top();
            res += tmp;
            pq.pop();
            pq.push((tmp + 2) / 3);
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();
    auto res = obj->maxKelements(nums, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
