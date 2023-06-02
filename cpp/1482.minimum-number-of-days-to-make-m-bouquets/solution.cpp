// Created by zwyyy456 at 2023/06/02 10:46
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

/*
1482. Minimum Number of Days to Make m Bouquets (Medium)
You are given an integer array `bloomDay`, an integer `m` and an integer `k`.

You want to make `m` bouquets. To make a bouquet, you need to use `k` **adjacent flowers** from the
garden.

The garden consists of `n` flowers, the `ith` flower will bloom in the `bloomDay[i]` and then can be
used in **exactly one** bouquet.

Return the minimum number of days you need to wait to be able to make  `m` bouquets from the garden.
If it is impossible to make m bouquets return `-1`.

**Example 1:**

```
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means
flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

```

**Example 2:**

```
Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5
flowers so it is impossible to get the needed bouquets and we return -1.

```

**Example 3:**

```
Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from
the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.

```

**Constraints:**

- `bloomDay.length == n`
- `1 <= n <= 10⁵`
- `1 <= bloomDay[i] <= 10⁹`
- `1 <= m <= 10⁶`
- `1 <= k <= n`

*/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool Check(vector<int> &bloomDay, int day, int m, int k) {
        // 双指针判断是否可以组成花束
        int l = 0, r = 0, cnt = 0;
        while (r < bloomDay.size() && cnt < m) {
            if (bloomDay[r] <= day) {
                if (r - l + 1 == k) {
                    ++cnt;
                    l = ++r;
                } else {
                    ++r;
                }
            } else {
                l = ++r;
            }
        }
        return cnt >= m;
    }
    int minDays(vector<int> &bloomDay, int m, int k) {
        int left = 1, right = 1;
        int n = bloomDay.size();
        if (m * k > n) {
            return -1;
        }
        for (int i : bloomDay) {
            right = max(right, i);
        }
        right++;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (!Check(bloomDay, mid, m, k)) {
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

    vector<int> bloomDay;
    LeetCodeIO::scan(cin, bloomDay);
    int m;
    LeetCodeIO::scan(cin, m);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();

    auto res = obj->minDays(bloomDay, m, k);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
