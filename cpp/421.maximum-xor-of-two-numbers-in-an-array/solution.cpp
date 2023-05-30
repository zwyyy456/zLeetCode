// Created by zwyyy456 at 2023/05/30 14:39
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

/*
421. Maximum XOR of Two Numbers in an Array (Medium)
Given an integer array `nums`, return the maximum result of  `nums[i] XOR nums[j]`, where `0 <= i <=
j < n`.

**Example 1:**

```
Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

```

**Example 2:**

```
Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127

```

**Constraints:**

- `1 <= nums.length <= 2 * 10⁵`
- `0 <= nums[i] <= 2³¹ - 1`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums; LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();

	auto res = obj->findMaximumXOR(nums);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
