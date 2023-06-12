// Created by Bob at 2023/05/30 09:54
// https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/

/*
421. 数组中两个数的最大异或值 (Medium)
给你一个整数数组 `nums` ，返回 `nums[i] XOR nums[j]` 的最大
运算结果，其中 `0 ≤ i ≤ j < n` 。

**示例 1：**

```
输入：nums = [3,10,5,25,2,8]
输出：28
解释：最大运算结果是 5 XOR 25 = 28.
```

**示例 2：**

```
输入：nums = [14,70,53,83,49,91,36,80,92,51,66,70]
输出：127

```

**提示：**

- `1 <= nums.length <= 2 * 10⁵`
- `0 <= nums[i] <= 2³¹ - 1`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
class Trie {
  public:
    Trie() :
        tree_{nullptr, nullptr}, end_(false) {
    }
    void Insert(int num) {
        Trie *node = this;
        for (int i = 31; i >= 0; --i) {
            int idx = ((num >> i) & 1);
            if (node->tree_[idx] == nullptr) {
                node->tree_[idx] = new Trie();
            }
            node = node->tree_[idx];
        }
        node->end_ = true;
    }
    int Count(int x) {
        Trie *node = this;
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            int a = (x >> i) & 1, b = 1 - a;
            if (node->tree_[b] != nullptr) {
                res |= (1 << i);
                node = node->tree_[b];
            } else {
                node = node->tree_[a];
            }
        }
        return res;
    }

  private:
    vector<Trie *> tree_;
    bool end_;
};
class Solution {
  public:
    int findMaximumXOR(vector<int> &nums) {
        int res = 0;
        Trie *tree = new Trie();
        for (auto num : nums) {
            tree->Insert(num);
        }
        for (auto num : nums) {
            res = max(res, tree->Count(num));
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

    auto res = obj->findMaximumXOR(nums);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
