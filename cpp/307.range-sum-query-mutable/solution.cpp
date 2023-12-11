// Created by zwyyy456 at 2023/11/13 10:59
// leetgo: 1.3.8
// https://leetcode.com/problems/range-sum-query-mutable/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class NumArray {
  public:
    // 树状数组
    int lowbit(int x) {
        return x & (-x);
    }
    NumArray(vector<int> &nums) :
        tree(nums.size() + 1), len(nums.size()) {
        for (int i = 0; i < nums.size(); ++i) {
            tree_update(i + 1, nums[i]);
        }
    }

    void update(int index, int val) {
        int x = index + 1;
        int origin = sumRange(index, index);
        // while (x <= len) {
        // 	tree[x] += val - origin;
        // 	x += lowbit(x);
        // }
        tree_update(x, val - origin);
    }
    void tree_update(int x, int diff) {
        while (x <= len) {
            tree[x] += diff;
            x += lowbit(x);
        }
    }

    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
    int sum(int r) {
        int res = 0;
        while (r > 0) {
            res += tree[r];
            r -= lowbit(r);
        }
        return res;
    }

  private:
    vector<int> tree;
    int len;
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    NumArray *obj;
    const unordered_map<string, function<void()>> methods = {
        {"NumArray", [&]() {
             vector<int> nums;
             LeetCodeIO::scan(cin, nums);
             cin.ignore();
             obj = new NumArray(nums);
             out_stream << "null,";
         }},
        {"update", [&]() {
             int index;
             LeetCodeIO::scan(cin, index);
             cin.ignore();
             int val;
             LeetCodeIO::scan(cin, val);
             cin.ignore();
             obj->update(index, val);
             out_stream << "null,";
         }},
        {"sumRange", [&]() {
             int left;
             LeetCodeIO::scan(cin, left);
             cin.ignore();
             int right;
             LeetCodeIO::scan(cin, right);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->sumRange(left, right));
             out_stream << ',';
         }},
    };
    cin >> ws;
    out_stream << '[';
    for (auto &&method_name : method_names) {
        cin.ignore(2);
        methods.at(method_name)();
    }
    cin.ignore();
    out_stream.seekp(-1, ios_base::end);
    out_stream << ']';
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
