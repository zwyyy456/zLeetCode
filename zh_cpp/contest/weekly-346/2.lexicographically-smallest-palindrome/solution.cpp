// Created by Bob at 2023/05/21 10:31
// https://leetcode.cn/problems/lexicographically-smallest-palindrome/
// https://leetcode.cn/contest/weekly-contest-346/problems/lexicographically-smallest-palindrome/

/*
6454. 字典序最小回文串 (Easy)
给你一个由 **小写英文字母** 组成的字符串 `s` ，你可以对其执
行一些操作。在一步操作中，你可以用其他小写英文字母 **替换** 
`s` 中的一个字符。

请你执行 **尽可能少的操作** ，使 `s` 变成一个 **回文串** 。
如果执行 **最少** 操作次数的方案不止一种，则只需选取 **字典
序最小** 的方案。

对于两个长度相同的字符串 `a` 和 `b` ，在 `a` 和 `b` 出现不同
的第一个位置，如果该位置上 `a` 中对应字母比 `b` 中对应字母在
字母表中出现顺序更早，则认为 `a` 的字典序比 `b` 的字典序要小
。

返回最终的回文字符串。

**示例 1：**

```
输入：s = "egcfe"
输出："efcfe"
解释：将 "egcfe" 变成回文字符串的最小操作次数为 1 ，修改 1 
次得到的字典序最小回文字符串是 "efcfe"，只需将 'g' 改为 'f' 
。

```

**示例 2：**

```
输入：s = "abcd"
输出："abba"
解释：将 "abcd" 变成回文字符串的最小操作次数为 2 ，修改 2 次
得到的字典序最小回文字符串是 "abba" 。

```

**示例 3：**

```
输入：s = "seven"
输出："neven"
解释：将 "seven" 变成回文字符串的最小操作次数为 1 ，修改 1 
次得到的字典序最小回文字符串是 "neven" 。
```

**提示：**

- `1 <= s.length <= 1000`
- `s` 仅由小写英文字母组成

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    string makeSmallestPalindrome(string s) {
       	int n = s.size();
       	vector<char> str(n);
       	int left = 0, right = n - 1;
       	while (left <= right) {
       		// if (s[left] == s[right]) {
       		// 	str[left] = s[left];
       		// 	str[right] = s[right];
       		// } else {
       			str[left] = min(s[left], s[right]);
       			str[right] = min(s[left], s[right]);
       			++left;
       			--right;
       		// }
       	} 
       	string res(str.begin(), str.end());
       	return res;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s; LeetCodeIO::scan(cin, s);

	Solution *obj = new Solution();

	auto res = obj->makeSmallestPalindrome(s);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
