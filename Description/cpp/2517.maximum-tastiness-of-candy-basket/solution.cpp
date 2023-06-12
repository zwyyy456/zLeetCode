// Created by Bob at 2023/06/02 17:03
// https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/

/*
2517. 礼盒的最大甜蜜度 (Medium)
给你一个正整数数组 `price` ，其中 `price[i]` 表示第 `i` 类糖
果的价格，另给你一个正整数 `k` 。

商店组合 `k` 类 **不同** 糖果打包成礼盒出售。礼盒的 **甜蜜度
** 是礼盒中任意两种糖果 **价格** 绝对差的最小值。

返回礼盒的 **最大** 甜蜜度。

**示例 1：**

```
输入：price = [13,5,1,8,21,2], k = 3
输出：8
解释：选出价格分别为 [13,5,21] 的三类糖果。
礼盒的甜蜜度为 min(|13 - 5|, |13 - 21|, |5 - 21|) = min(8, 8
, 16) = 8 。
可以证明能够取得的最大甜蜜度就是 8 。

```

**示例 2：**

```
输入：price = [1,3,1], k = 2
输出：2
解释：选出价格分别为 [1,3] 的两类糖果。
礼盒的甜蜜度为 min(|1 - 3|) = min(2) = 2 。
可以证明能够取得的最大甜蜜度就是 2 。

```

**示例 3：**

```
输入：price = [7,7,7,7], k = 2
输出：0
解释：从现有的糖果中任选两类糖果，甜蜜度都会是 0 。

```

**提示：**

- `1 <= price.length <= 10⁵`
- `1 <= price[i] <= 10⁹`
- `2 <= k <= price.length`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> price; LeetCodeIO::scan(cin, price);
	int k; LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();

	auto res = obj->maximumTastiness(price, k);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
