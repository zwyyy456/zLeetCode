// Created by zwyyy456 at 2023/05/21 11:18
// https://leetcode.com/problems/search-in-rotated-sorted-array/

/*
33. Search in Rotated Sorted Array (Medium)
There is an integer array `nums` sorted in ascending order (with **distinct** values).

Prior to being passed to your function, `nums` is **possibly rotated** at an unknown pivot index `k`
( `1 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1],
nums[0], nums[1], ..., nums[k-1]]` ( **0-indexed**). For example, `[0,1,2,4,5,6,7]` might be rotated
at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` **after** the possible rotation and an integer `target`, return the index of
`target` if it is in  `nums`, or  `-1` if it is not in  `nums`.

You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

```

**Example 2:**

```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

```

**Example 3:**

```
Input: nums = [1], target = 0
Output: -1

```

**Constraints:**

- `1 <= nums.length <= 5000`
- `-10⁴ <= nums[i] <= 10⁴`
- All values of `nums` are **unique**.
- `nums` is an ascending array that is possibly rotated.
- `-10⁴ <= target <= 10⁴`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums; LeetCodeIO::scan(cin, nums);
	int target; LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();

	auto res = obj->search(nums, target);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
