// Created by zwyyy456 at 2023/05/10 16:11
// https://leetcode.com/problems/smallest-integer-divisible-by-k/

/*
1015. Smallest Integer Divisible by K (Medium)
Given a positive integer `k`, you need to find the **length** of the **smallest** positive integer
`n` such that `n` is divisible by `k`, and `n` only contains the digit `1`.

Return the **length** of  `n`. If there is no such `n`, return -1.

**Note:** `n` may not fit in a 64-bit signed integer.

**Example 1:**

```
Input: k = 1
Output: 1
Explanation: The smallest answer is n = 1, which has length 1.

```

**Example 2:**

```
Input: k = 2
Output: -1
Explanation: There is no such positive integer n divisible by 2.

```

**Example 3:**

```
Input: k = 3
Output: 3
Explanation: The smallest answer is n = 111, which has length 3.

```

**Constraints:**

- `1 <= k <= 10⁵`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
        vector<int> arr(k);
        int num = 0;
        for (int i = 0; i < k; ++i) {
            num = num * 10 + 1;
            num = num % k;
            if (num == 0) {
                return i + 1;
            } else {
                if (arr[num] == 1) {
                    return -1;
                }
                arr[num] = 1;
            }
        }
        return 0;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();

    auto res = obj->smallestRepunitDivByK(k);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
