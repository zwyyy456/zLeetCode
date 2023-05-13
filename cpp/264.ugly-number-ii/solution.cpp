// Created by zwyyy456 at 2023/05/06 14:46
// https://leetcode.com/problems/ugly-number-ii/

/*
264. Ugly Number II (Medium)
An **ugly number** is a positive integer whose prime factors are limited to `2`, `3`, and `5`.

Given an integer `n`, return the `nth`**ugly number**.

**Example 1:**

```
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

```

**Example 2:**

```
Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

```

**Constraints:**

- `1 <= n <= 1690`

*/

#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <unordered_set>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int nthUglyNumber(int n) {
        vector<int> arr(n);
        arr[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        int idx = 0;
        while (idx < n) {
            int num2 = arr[p2] * 2;
            int num3 = arr[p3] * 3;
            int num5 = arr[p5] * 5;
            int min_num = min(num2, min(num3, num5));
            if (num2 == min_num) {
                ++p2;
            }
            if (num3 == min_num) {
                ++p3;
            }
            if (num5 == min_num) {
                ++p5;
            }
            arr[++idx] = min_num;
        }
        return arr[n - 1];
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();

    auto res = obj->nthUglyNumber(n);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
