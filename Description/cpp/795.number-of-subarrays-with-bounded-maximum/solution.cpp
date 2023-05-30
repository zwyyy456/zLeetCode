// Created by Bob at 2023/05/21 18:31
// https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/

/*
795. 区间子数组个数 (Medium)
给你一个整数数组 `nums` 和两个整数： `left` 及 `right` 。找
出 `nums` 中连续、非空且其中最大元素在范围 `[left, right]` 
内的子数组，并返回满足条件的子数组的个数。

生成的测试用例保证结果符合 **32-bit** 整数范围。

**示例 1：**

```
输入：nums = [2,1,4,3], left = 2, right = 3
输出：3
解释：满足条件的三个子数组：[2], [2, 1], [3]

```

**示例 2：**

```
输入：nums = [2,9,2,5,6], left = 2, right = 8
输出：7

```

**提示：**

- `1 <= nums.length <= 10⁵`
- `0 <= nums[i] <= 10⁹`
- `0 <= left <= right <= 10⁹`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums; LeetCodeIO::scan(cin, nums);
	int left; LeetCodeIO::scan(cin, left);
	int right; LeetCodeIO::scan(cin, right);

	Solution *obj = new Solution();

	auto res = obj->numSubarrayBoundedMax(nums, left, right);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
