// Created by zwyyy456 at 2023/06/08 09:48
// https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/

/*
1240. Tiling a Rectangle with the Fewest Squares (Hard)
Given a rectangle of size `n` x `m`, return the minimum number of integer-sided squares that tile the
rectangle.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/10/17/sample_11_1592.png)

```
Input: n = 2, m = 3
Output: 3
Explanation: 3 squares are necessary to cover the rectangle.
2 (squares of 1x1)
1 (square of 2x2)
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/10/17/sample_22_1592.png)

```
Input: n = 5, m = 8
Output: 5

```

**Example 3:**

![](https://assets.leetcode.com/uploads/2019/10/17/sample_33_1592.png)

```
Input: n = 11, m = 13
Output: 6

```

**Constraints:**

- `1 <= n, m <= 13`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int tilingRectangle(int n, int m) {
        if (n < m) {
            swap(n, m);
        }
        // 保证 n > m；
        if (n % m == 0) {
            return n / m;
        }
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    int m;
    LeetCodeIO::scan(cin, m);

    Solution *obj = new Solution();

    auto res = obj->tilingRectangle(n, m);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
