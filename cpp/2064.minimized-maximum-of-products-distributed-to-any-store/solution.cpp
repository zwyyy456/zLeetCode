// Created by zwyyy456 at 2023/06/01 15:19
// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

/*
2064. Minimized Maximum of Products Distributed to Any Store (Medium)
You are given an integer `n` indicating there are `n` specialty retail stores. There are `m` product
types of varying amounts, which are given as a **0-indexed** integer array `quantities`, where
`quantities[i]` represents the number of products of the `ith` product type.

You need to distribute **all products** to the retail stores following these rules:

- A store can only be given **at most one product type** but can be given **any** amount of it.
- After distribution, each store will have been given some number of products (possibly `0`). Let `x`
represent the maximum number of products given to any store. You want `x` to be as small as
possible, i.e., you want to **minimize** the **maximum** number of products that are given to any
store.

Return the minimum possible `x`.

**Example 1:**

```
Input: n = 6, quantities = [11,6]
Output: 3
Explanation: One optimal way is:
- The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
- The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.

```

**Example 2:**

```
Input: n = 7, quantities = [15,10,10]
Output: 5
Explanation: One optimal way is:
- The 15 products of type 0 are distributed to the first three stores in these amounts: 5, 5, 5
- The 10 products of type 1 are distributed to the next two stores in these amounts: 5, 5
- The 10 products of type 2 are distributed to the last two stores in these amounts: 5, 5
The maximum number of products given to any store is max(5, 5, 5, 5, 5, 5, 5) = 5.

```

**Example 3:**

```
Input: n = 1, quantities = [100000]
Output: 100000
Explanation: The only optimal way is:
- The 100000 products of type 0 are distributed to the only store.
The maximum number of products given to any store is max(100000) = 100000.

```

**Constraints:**

- `m == quantities.length`
- `1 <= m <= n <= 10⁵`
- `1 <= quantities[i] <= 10⁵`

*/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool Check(int n, vector<int> &quantities, int cnt) {
        long res = 0;
        for (int num : quantities) {
            res += (num - 1) / cnt + 1;
        }
        return res <= n;
    }
    int minimizedMaximum(int n, vector<int> &quantities) {
        // 二分答案
        int left = 1, right = 100001;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (!Check(n, quantities, mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    vector<int> quantities;
    LeetCodeIO::scan(cin, quantities);

    Solution *obj = new Solution();

    auto res = obj->minimizedMaximum(n, quantities);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
