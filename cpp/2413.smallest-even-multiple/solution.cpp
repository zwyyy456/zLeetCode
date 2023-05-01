// Created by zwyyy456 at 2023/04/21 13:44
// https://leetcode.com/problems/smallest-even-multiple/

/*
2413. Smallest Even Multiple (Easy)
Given a **positive** integer `n`, return the smallest positive integer that is a multiple of
**both** `2` and  `n`.

**Example 1:**

```
Input: n = 5
Output: 10
Explanation: The smallest multiple of both 5 and 2 is 10.

```

**Example 2:**

```
Input: n = 6
Output: 6
Explanation: The smallest multiple of both 6 and 2 is 6. Note that a number is a multiple of itself.

```

**Constraints:**

- `1 <= n <= 150`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int smallestEvenMultiple(int n) {
        return n % 2 ? 2 * n : n;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();

    auto res = obj->smallestEvenMultiple(n);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
