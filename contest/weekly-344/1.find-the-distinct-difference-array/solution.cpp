// Created by zwyyy456 at 2023/05/07 14:28
// https://leetcode.com/problems/find-the-distinct-difference-array/
// https://leetcode.com/contest/weekly-contest-344/problems/find-the-distinct-difference-array/

/*
2670. Find the Distinct Difference Array (Easy)
You are given a **0-indexed** array `nums` of length `n`.

The **distinct difference** array of `nums` is an array `diff` of length `n` such that `diff[i]` is
equal to the number of distinct elements in the suffix `nums[i + 1, ..., n - 1]` **subtracted from**
the number of distinct elements in the prefix `nums[0, ..., i]`.

Return the **distinct difference** array of  `nums`.

Note that `nums[i, ..., j]` denotes the subarray of `nums` starting at index `i` and ending at index
`j` inclusive. Particularly, if `i > j` then `nums[i, ..., j]` denotes an empty subarray.

**Example 1:**

```
Input: nums = [1,2,3,4,5]
Output: [-3,-1,1,3,5]
Explanation: For index i = 0, there is 1 element in the prefix and 4 distinct elements in the
suffix. Thus, diff[0] = 1 - 4 = -3.
For index i = 1, there are 2 distinct elements in the prefix and 3 distinct elements in the suffix.
Thus, diff[1] = 2 - 3 = -1.
For index i = 2, there are 3 distinct elements in the prefix and 2 distinct elements in the suffix.
Thus, diff[2] = 3 - 2 = 1.
For index i = 3, there are 4 distinct elements in the prefix and 1 distinct element in the suffix.
Thus, diff[3] = 4 - 1 = 3.
For index i = 4, there are 5 distinct elements in the prefix and no elements in the suffix. Thus,
diff[4] = 5 - 0 = 5.

```

**Example 2:**

```
Input: nums = [3,2,3,4,2]
Output: [-2,-1,0,2,3]
Explanation: For index i = 0, there is 1 element in the prefix and 3 distinct elements in the
suffix. Thus, diff[0] = 1 - 3 = -2.
For index i = 1, there are 2 distinct elements in the prefix and 3 distinct elements in the suffix.
Thus, diff[1] = 2 - 3 = -1.
For index i = 2, there are 2 distinct elements in the prefix and 2 distinct elements in the suffix.
Thus, diff[2] = 2 - 2 = 0.
For index i = 3, there are 3 distinct elements in the prefix and 1 distinct element in the suffix.
Thus, diff[3] = 3 - 1 = 2.
For index i = 4, there are 3 distinct elements in the prefix and no elements in the suffix. Thus,
diff[4] = 3 - 0 = 3.

```

**Constraints:**

- `1 <= n == nums.length <= 50`
- `1 <= nums[i] <= 50`

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int, int> full;
        for (int i : nums) {
        	++full[nums[i]];
        }
        unordered_map<int, int> front;
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
        	front[nums[i]]++;
        	if (--full[nums[i]] == 0) {
        		full.erase(nums[i]);
        	}
        	res[i] = front.size() - full.size();
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

	auto res = obj->distinctDifferenceArray(nums);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
