// Created by zwyyy456 at 2023/08/18 14:02
// leetgo: 1.3.5
// https://leetcode.com/problems/contains-duplicate-iii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool check(map<int, int> &recs, int val, int num) {
        if (recs.lower_bound(num - val) == recs.end() || recs.lower_bound(num - val)->first > num + val) {
            return false;
        }
        return true;
    }
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff) {
        int n = nums.size(), k = indexDiff, val = valueDiff;
        map<int, int> recs;
        // 包含 k 个元素的红黑树
        // 红黑树表示元素的出现次数
        for (int i = 0; i < min(n, k); ++i) {
            if (recs.empty()) {
                ++recs[nums[i]];
                continue;
            }
            if (!check(recs, val, nums[i])) {
                ++recs[nums[i]];
                continue;
            }
            return true;
        }
        for (int i = k; i < n; ++i) {
            if (check(recs, val, nums[i])) {
                return true;
            }
            ++recs[nums[i]];
            int num = nums[i - k];
            if (--recs[num] == 0) {
                recs.erase(num);
            }
        }
        return false;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);
    int indexDiff;
    LeetCodeIO::scan(cin, indexDiff);
    int valueDiff;
    LeetCodeIO::scan(cin, valueDiff);

    Solution *obj = new Solution();
    auto res = obj->containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
