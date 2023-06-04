// Created by Bob at 2023/05/29 13:26
// https://leetcode.cn/problems/power-of-heroes/

/*
2681. 英雄的力量 (Hard)
给你一个下标从 **0** 开始的整数数组 `nums` ，它表示英雄的能
力值。如果我们选出一部分英雄，这组英雄的 **力量** 定义为：

- `i₀` ， `i₁` ，... `iₖ` 表示这组英雄在数组中的下标。那么这
组英雄的力量为 `max(nums[i₀],nums[i₁] ... nums[iₖ])² * min(n
ums[i₀],nums[i₁] ... nums[iₖ])` 。

请你返回所有可能的 **非空** 英雄组的 **力量** 之和。由于答案
可能非常大，请你将结果对 `10⁹ + 7` **取余。**

**示例 1：**

```
输入：nums = [2,1,4]
输出：141
解释：
第 1 组：[2] 的力量为 2² * 2 = 8 。
第 2 组：[1] 的力量为 1² * 1 = 1 。
第 3 组：[4] 的力量为 4² * 4 = 64 。
第 4 组：[2,1] 的力量为 2² * 1 = 4 。
第 5 组：[2,4] 的力量为 4² * 2 = 32 。
第 6 组：[1,4] 的力量为 4² * 1 = 16 。
第 7 组：[2,1,4] 的力量为 4² * 1 = 16 。
所有英雄组的力量之和为 8 + 1 + 64 + 4 + 32 + 16 + 16 = 141 
。

```

**示例 2：**

```
输入：nums = [1,1,1]
输出：7
解释：总共有 7 个英雄组，每一组的力量都是 1 。所以所有英雄组
的力量之和为 7 。

```

**提示：**

- `1 <= nums.length <= 10⁵`
- `1 <= nums[i] <= 10⁹`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums; LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();

	auto res = obj->sumOfPower(nums);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
