// Created by zwyyy456 at 2023/10/05 19:56
// leetgo: 1.3.8
// https://leetcode.com/problems/count-of-range-sum/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
class TreeArr {
  public:
    TreeArr(int n) :
        arr(n + 1), len(n) {
    }
    int lowbit(int x) {
        return x & (~x);
    }
    void update(int x) {
        while (x <= len) {
            arr[x] += 1;
            x = x + lowbit(x);
        }
    }
    int getsum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += arr[x];
            x = x - lowbit(x);
        }
        return sum;
    }

  private:
    vector<int> arr;
    int len;
};
class Solution {
  public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        // 求区间和，并进行离散化
        set<int> sums;
        int n = nums.size();
        sums.insert(0);
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += nums[i - 1];
            sums.insert(sum);
            sums.insert(sum - lower);
            sums.insert(sum - upper);
        }
        unordered_map<int, int> num2num;
        int idx = 1;
        // 完成映射
        for (int i : sums) {
            num2num[i] = idx;
            ++idx;
        }
        TreeArr *arr = new TreeArr(sums.size());
        arr->update(num2num[0]);
        sum = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            res = arr->getsum(num2num[sum - lower]) - arr->getsum(num2num[sum - upper - 1]);
            arr->update(num2num[sum]);
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
    int lower;
    LeetCodeIO::scan(cin, lower);
    int upper;
    LeetCodeIO::scan(cin, upper);

    Solution *obj = new Solution();
    auto res = obj->countRangeSum(nums, lower, upper);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
