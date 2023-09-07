// Created by zwyyy456 at 2023/08/26 11:38
// leetgo: 1.3.1
// https://leetcode.com/problems/advantage-shuffle/

#include <bits/stdc++.h>
#include <queue>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
        queue<int> nomatch;
        priority_queue<int> nums;
        auto cmp = [&nums2](int l, int r) {
            return nums2[l] < nums2[r];
        };
        priority_queue<int, vector<int>, decltype(cmp)> index(cmp);
        int n = nums1.size();
        for (int i = 0; i < n; ++i) {
            nums.push(nums1[i]);
        }
        for (int i = 0; i < n; ++i) {
            index.push(i);
        }
        vector<int> res(n);
        while (!nums.empty() && !index.empty()) {
            if (nums.top() > nums2[index.top()]) {
                res[index.top()] = nums.top();
                nums.pop();
                index.pop();
            } else {
                nomatch.push(index.top());
                index.pop();
            }
        }
        while (!nums.empty()) {
            res[nomatch.front()] = nums.top();
            nomatch.pop();
            nums.pop();
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums1;
    LeetCodeIO::scan(cin, nums1);
    vector<int> nums2;
    LeetCodeIO::scan(cin, nums2);

    Solution *obj = new Solution();

    auto res = obj->advantageCount(nums1, nums2);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
