// Created by zwyyy456 at 2023/05/11 09:51
// https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/

/*
1016. Binary String With Substrings Representing 1 To N (Medium)
Given a binary string `s` and a positive integer `n`, return `true` if the binary representation of
all the integers in the range  `[1, n]` are **substrings** of  `s`, or  `false` otherwise.

A **substring** is a contiguous sequence of characters within a string.

**Example 1:**

```
Input: s = "0110", n = 3
Output: true

```

**Example 2:**

```
Input: s = "0110", n = 4
Output: false

```

**Constraints:**

- `1 <= s.length <= 1000`
- `s[i]` is either `'0'` or `'1'`.
- `1 <= n <= 10⁹`

*/

#include <bits/stdc++.h>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool queryString(string s, int n) {
       	unordered_set<int> nums;
       	int m = s.size();
       	for (int i = 0; i < m; ++i) {
       		int num = s[i] - '0';
       		if (num == 1) {
       		nums.insert(num);
       		}
       		for (int j = i + 1; j < m; ++j) {
       			num = 2 * num + s[j] - '0';
       			if (num <= n) {
       				nums.insert(num);
       			}
       		}
       	} 
       	return nums.size() == n;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s; LeetCodeIO::scan(cin, s);
	int n; LeetCodeIO::scan(cin, n);

	Solution *obj = new Solution();

	auto res = obj->queryString(s, n);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
