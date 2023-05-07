// Created by Bob at 2023/05/06 16:35
// https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/

/*
373. 查找和最小的 K 对数字 (Medium)
给定两个以 **升序排列** 的整数数组 `nums1` 和 `nums2`, 以及
一个整数 `k`。

定义一对值 `(u,v)`，其中第一个元素来自 `nums1`，第二个元素来
自 `nums2`。

请找到和最小的 `k` 个数对 `(u₁,v₁)`, ` (u₂,v₂)`  ...  `(uₖ,v
ₖ)` 。

**示例 1:**

```
输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
输出: [1,2],[1,4],[1,6]
解释: 返回序列中的前 3 对数：
     [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6
]

```

**示例 2:**

```
输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
输出: [1,1],[1,1]
解释: 返回序列中的前 2 对数：
     [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

```

**示例 3:**

```
输入: nums1 = [1,2], nums2 = [3], k = 3
输出: [1,3],[2,3]
解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]

```

**提示:**

- `1 <= nums1.length, nums2.length <= 10⁵`
- `-10⁹ <= nums1[i], nums2[i] <= 10⁹`
- `nums1` 和 `nums2` 均为升序排列
- `1 <= k <= 1000`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums1; LeetCodeIO::scan(cin, nums1);
	vector<int> nums2; LeetCodeIO::scan(cin, nums2);
	int k; LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();

	auto res = obj->kSmallestPairs(nums1, nums2, k);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
