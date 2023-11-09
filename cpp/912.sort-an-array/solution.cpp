// Created by zwyyy456 at 2023/10/10 21:12
// leetgo: 1.3.8
// https://leetcode.com/problems/sort-an-array/

#include <algorithm>
#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int mpart(vector<int> &nums, int l, int r) {
        int pivot = nums[l];
        int i = l, j = r + 1;
        while (true) {
            while (nums[++i] < pivot) {
                if (i == r) {
                    break;
                }
            }
            while (nums[--j] > pivot) {
                if (j == l) {
                    break;
                }
            }
            if (i >= j) {
                break;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        return j;
    }
    void qsort(vector<int> &nums, int l, int r) {
        // 左闭右开
        if (l < r) {
            int pivot = mpart(nums, l, r);
            qsort(nums, l, pivot - 1);
            qsort(nums, pivot + 1, r);
        }
    }
    vector<int> sortArray(vector<int> &nums) {
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();
    auto res = obj->sortArray(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
