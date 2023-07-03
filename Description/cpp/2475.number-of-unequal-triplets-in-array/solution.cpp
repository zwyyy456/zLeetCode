// Created by Bob at 2023/06/13 16:24
// https://leetcode.cn/problems/number-of-unequal-triplets-in-array/

/*
2475. 数组中不等三元组的数目 (Easy)
给你一个下标从 **0** 开始的正整数数组 `nums` 。请你找出并统
计满足下述条件的三元组 `(i, j, k)` 的数目：

- `0 <= i < j < k < nums.length`
- `nums[i]`、 `nums[j]` 和 `nums[k]` **两两不同** 。

  - 换句话说： `nums[i] != nums[j]`、 `nums[i] != nums[k]` 
且 `nums[j] != nums[k]` 。

返回满足上述条件三元组的数目。

**示例 1：**

```
输入：nums = [4,4,2,4,3]
输出：3
解释：下面列出的三元组均满足题目条件：
- (0, 2, 4) 因为 4 != 2 != 3
- (1, 2, 4) 因为 4 != 2 != 3
- (2, 3, 4) 因为 2 != 4 != 3
共计 3 个三元组，返回 3 。
注意 (2, 0, 4) 不是有效的三元组，因为 2 > 0 。

```

**示例 2：**

```
输入：nums = [1,1,1,1,1]
输出：0
解释：不存在满足条件的三元组，所以返回 0 。

```

**提示：**

- `3 <= nums.length <= 100`
- `1 <= nums[i] <= 1000`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums; LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();

	auto res = obj->unequalTriplets(nums);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
