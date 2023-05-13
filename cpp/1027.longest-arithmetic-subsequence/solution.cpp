// Created by zwyyy456 at 2023/04/22 14:27
// https://leetcode.com/problems/longest-arithmetic-subsequence/

/*
1027. Longest Arithmetic Subsequence (Medium)
Given an array `nums` of integers, return the length of the longest arithmetic subsequence in
`nums`.

**Note** that:

- A **subsequence** is an array that can be derived from another array by deleting some or no
elements without changing the order of the remaining elements.
- A sequence `seq` is arithmetic if `seq[i + 1] - seq[i]` are all the same value (for `0 <= i <
seq.length - 1`).

**Example 1:**

```
Input: nums = [3,6,9,12]
Output: 4
Explanation:  The whole array is an arithmetic sequence with steps of length = 3.

```

**Example 2:**

```
Input: nums = [9,4,7,2,10]
Output: 3
Explanation:  The longest arithmetic subsequence is [4,7,10].

```

**Example 3:**

```
Input: nums = [20,1,15,3,10,5,8]
Output: 4
Explanation:  The longest arithmetic subsequence is [20,15,10,5].

```

**Constraints:**

- `2 <= nums.length <= 1000`
- `0 <= nums[i] <= 500`

*/

#include <bits/stdc++.h>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
       	// 动态规划
       	int n = nums.size();
       	// 前 k 个字符，公差为 d 的 LAS 的最大长度
       	// dp[k][d] = max(dp[k - 1][d], dp[j][d] + 1); 其中 j 表示满足 nums[k - 1] - nums[j - 1] = d 的最大的 j
       	vector<unordered_map<int, int>> diff(n);
       	for (int i = 1; i < n; ++i) {
       		for (int j = 0; j < i; ++j) {
       			auto &ump = diff[i];
       			ump[nums[i] - nums[j]] = j;
       		}
       	}
       	vector<vector<int>> dp(n + 1, vector<int>(1001, 1)); // 差值从 -500 到 500
       	int res = 1;
       	for (int i = 2; i <= n; ++i) { // 考虑至少前 2 个元素
       		auto &ump = diff[i - 1];
       		for (int j = 0; j <= 1000; ++j) {
       			int real_diff = j - 500;
       			if (ump.find(real_diff) != ump.end()) {
       				dp[i][j] = dp[ump[real_diff] + 1][j] + 1;
       			} else {
       				dp[i][j] = 1;
       			}
       			res = max(res, dp[i][j]);
       		}
       	}
       	return res;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums; LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();

	auto res = obj->longestArithSeqLength(nums);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
