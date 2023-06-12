// Created by zwyyy456 at 2023/06/02 10:09
// https://leetcode.com/problems/longest-turbulent-subarray/

/*
978. Longest Turbulent Subarray (Medium)
Given an integer array `arr`, return the length of a maximum size turbulent subarray of `arr`.

A subarray is **turbulent** if the comparison sign flips between each adjacent pair of elements in
the subarray.

More formally, a subarray `[arr[i], arr[i + 1], ..., arr[j]]` of `arr` is said to be turbulent if
and only if:

- For `i <= k < j`:

  - `arr[k] > arr[k + 1]` when `k` is odd, and
  - `arr[k] < arr[k + 1]` when `k` is even.
- Or, for `i <= k < j`:

  - `arr[k] > arr[k + 1]` when `k` is even, and
  - `arr[k] < arr[k + 1]` when `k` is odd.

**Example 1:**

```
Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]

```

**Example 2:**

```
Input: arr = [4,8,12,16]
Output: 2

```

**Example 3:**

```
Input: arr = [100]
Output: 1

```

**Constraints:**

- `1 <= arr.length <= 4 * 10⁴`
- `0 <= arr[i] <= 10⁹`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maxTurbulenceSize(vector<int> &arr) {
        // dp
        int n = arr.size();
        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = arr[1] == arr[0] ? 1 : 2;
        int res = 1;
        for (int i = 2; i < n; ++i) {
            if (arr[i] == arr[i - 1]) {
                dp[i] = 1;
            } else {
                if ((arr[i] - arr[i - 1]) * (arr[i - 1] * arr[i - 2]) < 0) {
                    dp[i] = dp[i - 1] + 1;
                } else {
                    dp[i] = 2;
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> arr;
    LeetCodeIO::scan(cin, arr);

    Solution *obj = new Solution();

    auto res = obj->maxTurbulenceSize(arr);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
