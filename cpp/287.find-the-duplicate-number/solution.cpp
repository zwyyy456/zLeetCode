// Created by zwyyy456 at 2023/08/04 10:07
// leetgo: 1.3.1
// https://leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h>
#include <numeric>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        // 快慢指针
        int fast = 0, slow = 0;
        while (1) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow) {
                break;
            }
        }
        slow = 0;
        int finder = fast;
        while (slow != finder) {
            slow = nums[slow];
            finder = nums[finder];
        }
        return slow;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();

    auto res = obj->findDuplicate(nums);

    LeetCodeIO::print(out_stream, res);
    cout << "output : " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
