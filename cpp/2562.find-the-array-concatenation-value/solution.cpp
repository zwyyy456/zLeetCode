// Created by zwyyy456 at 2023/10/12 09:17
// leetgo: 1.3.8
// https://leetcode.com/problems/find-the-array-concatenation-value/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int getnum(vector<int> &nums, int l, int r) {
        int tmp = nums[r];
        while (tmp != 0) {
            nums[l] *= 10;
            tmp /= 10;
        }
        return nums[l] + nums[r];
    }
    long long findTheArrayConcVal(vector<int> &nums) {
        long res = 0;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            res += getnum(nums, l, r);
            ++l;
            ++r;
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

    Solution *obj = new Solution();
    auto res = obj->findTheArrayConcVal(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
