// Created by zwyyy456 at 2023/08/13 13:21
// leetgo: 1.3.5
// https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int all = m + n;
        for (int i = m + n - 1; i >= 0; --i) {
            if (m > 0) {
                if (n > 0) {
                    if (nums1[m - 1] >= nums2[n - 1]) {
                        nums1[i] = nums2[n - 1];
                        --n;
                    } else {
                        nums1[i] = nums1[m - 1];
                        --m;
                    }
                } else {
                    nums1[i] = nums2[m - 1];
                    --m;
                }
            } else {
                nums1[i] = nums2[n - 1];
                --n;
            }
        }
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums1;
    LeetCodeIO::scan(cin, nums1);
    int m;
    LeetCodeIO::scan(cin, m);
    vector<int> nums2;
    LeetCodeIO::scan(cin, nums2);
    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();
    auto res = obj->merge(nums1, m, nums2, n);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
