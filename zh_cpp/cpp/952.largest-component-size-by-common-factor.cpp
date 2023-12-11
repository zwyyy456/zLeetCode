// Created by Bob at 2023/03/22 19:27
// https://leetcode.cn/problems/largest-component-size-by-common-factor/

/*
952. 按公因数计算最大组件大小 (Hard)

给定一个由不同正整数的组成的非空数组 `nums` ，考虑下面的图：

- 有 `nums.length` 个节点，按从 `nums[0]` 到 `nums[nums.length - 1]`
标记；
- 只有当 `nums[i]` 和 `nums[j]` 共用一个大于 1 的公因数时， `nums[i]` 和
`nums[j]` 之间才有一条边。

返回 图中最大连通组件的大小 。

**示例 1：**

![](https://assets.leetcode.com/uploads/2018/12/01/ex1.png)

```
输入：nums = [4,6,15,35]
输出：4

```

**示例 2：**

![](https://assets.leetcode.com/uploads/2018/12/01/ex2.png)

```
输入：nums = [20,50,9,63]
输出：2

```

**示例 3：**

![](https://assets.leetcode.com/uploads/2018/12/01/ex3.png)

```
输入：nums = [2,3,6,7,4,12,21,39]
输出：8

```

**提示：**

- `1 <= nums.length <= 2 * 10⁴`
- `1 <= nums[i] <= 10⁵`
- `nums` 中所有值都 **不同**
*/

// @lc code=begin
#include <vector>
#include <numeric>
#include <functional>
using std::vector;
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
