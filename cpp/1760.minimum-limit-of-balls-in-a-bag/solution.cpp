// Created by zwyyy456 at 2023/11/10 21:59
// leetgo: 1.3.8
// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool check(vector<int> &nums, int mid, int k) {
        int cnt = 0;
        for (int num : nums) {
            cnt += (num - 1) / mid;
        }
        return cnt <= k;
    }
    int minimumSize(vector<int> &nums, int maxOperations) {
        int l = 1, r = 1e9 + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (!check(nums, mid, maxOperations)) {
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

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);
    int maxOperations;
    LeetCodeIO::scan(cin, maxOperations);

    Solution *obj = new Solution();
    auto res = obj->minimumSize(nums, maxOperations);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
