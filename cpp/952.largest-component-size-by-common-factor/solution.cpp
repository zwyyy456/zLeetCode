// Created by zwyyy456 at 2023/03/22 12:23
// https://leetcode.com/problems/largest-component-size-by-common-factor/

/*
952. Largest Component Size by Common Factor (Hard)

You are given an integer array of unique positive integers `nums`. Consider the following graph:

- There are `nums.length` nodes, labeled `nums[0]` to `nums[nums.length - 1]`,
- There is an undirected edge between `nums[i]` and `nums[j]` if `nums[i]` and `nums[j]` share a
common factor greater than `1`.

Return the size of the largest connected component in the graph.

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/12/01/ex1.png)

```
Input: nums = [4,6,15,35]
Output: 4

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2018/12/01/ex2.png)

```
Input: nums = [20,50,9,63]
Output: 2

```

**Example 3:**

![](https://assets.leetcode.com/uploads/2018/12/01/ex3.png)

```
Input: nums = [2,3,6,7,4,12,21,39]
Output: 8

```

**Constraints:**

- `1 <= nums.length <= 2 * 10⁴`
- `1 <= nums[i] <= 10⁵`
- All the values of `nums` are **unique**.
*/

// @lc code=begin
#include <vector>
#include <unordered_set>
#include <numeric>
#include <algorithm>
using std::unordered_set;
using std::vector;
class Dsu;
class Dsu {
public:
    vector<int> parent_;
    vector<int> size_; // 每棵树的节点数量
    int res;
public:
    Dsu(int n) : parent_(n), size_(n, 0), res(0) {
        iota(parent_.begin(), parent_.end(), 0); // parent[0] = 0, parent[1] = 1, 依次类推
    }
    int find(int idx) {
        return parent_[idx] == idx ? idx : parent_[idx] = find(parent_[idx]); 
    } 
    void unite(int idx, int idy) {
        idx = find(idx);
        idy = find(idy);
        if (idx == idy) {
            return;
        }
        if (size_[idx] < size_[idy]) {
            std::swap(idx, idy);
        }
        parent_[idy] = idx;
        size_[idx] += size_[idy];
    }

};
class Solution {
  public:
    void factor(int num, Dsu *dsu) {
        int tmp = num;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                while (num % i == 0) {
                    num /= i;
                }
                dsu->unite(i, tmp);
            }
        }
        if (num != 1) {
            dsu->unite(num, tmp);
        }
        dsu->res = std::max(dsu->res, dsu->size_[dsu->find(tmp)]);

    }
    int largestComponentSize(vector<int> &nums) {
        // 并查集，点集数量为n, 即nums.size()
        int n = nums.size();
        Dsu *dsu = new Dsu(100000 + 1);
        for (int i = 0; i < n; ++i) {
            dsu->size_[nums[i]] = 1;
        }
        for (int i = 0; i < n; ++i) {
            factor(nums[i], dsu);
        }
        return dsu->res;
    }
};






// @lc code=end
