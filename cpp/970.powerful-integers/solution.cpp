// Created by zwyyy456 at 2023/05/02 11:14
// https://leetcode.com/problems/powerful-integers/

/*
970. Powerful Integers (Medium)
Given three integers `x`, `y`, and `bound`, return a list of all the **powerful integers** that have
a value less than or equal to `bound`.

An integer is **powerful** if it can be represented as `xⁱ + yj` for some integers `i >= 0` and `j
>= 0`.

You may return the answer in **any order**. In your answer, each value should occur **at most
once**.

**Example 1:**

```
Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation:
2 = 2⁰ + 3⁰
3 = 2¹ + 3⁰
4 = 2⁰ + 3¹
5 = 2¹ + 3¹
7 = 2² + 3¹
9 = 2³ + 3⁰
10 = 2⁰ + 3²

```

**Example 2:**

```
Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]

```

**Constraints:**

- `1 <= x, y <= 100`
- `0 <= bound <= 10⁶`

*/

#include <bits/stdc++.h>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
       	if (x == 1 && y == 1) {
       		vector<int> res;
       		if (bound >= 2) {
       			res.emplace_back(2);
       		}
       		return res;
       	}
       	unordered_set<int> ust;
       	for (int i = 0; i <= 20 && pow(x, i) <= bound; ++i) {
       		for (int j = 0; j <= 20 && pow(y, j) <= bound; ++j) {
       			int tmp = pow(x, i) + pow(y, j);
       			if (tmp <= bound) {
       				ust.insert(tmp);
       			}
       		}
       	}
       	vector<int> res(ust.begin(), ust.end());
       	return res; 
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int x; LeetCodeIO::scan(cin, x);
	int y; LeetCodeIO::scan(cin, y);
	int bound; LeetCodeIO::scan(cin, bound);

	Solution *obj = new Solution();

	auto res = obj->powerfulIntegers(x, y, bound);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
