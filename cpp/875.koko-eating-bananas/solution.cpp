// Created by zwyyy456 at 2023/06/01 10:23
// https://leetcode.com/problems/koko-eating-bananas/

/*
875. Koko Eating Bananas (Medium)
Koko loves to eat bananas. There are `n` piles of bananas, the `ith` pile has `piles[i]` bananas.
The guards have gone and will come back in `h` hours.

Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she chooses some pile of bananas
and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them
instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer `k`such that she can eat all the bananas within `h`hours.

**Example 1:**

```
Input: piles = [3,6,7,11], h = 8
Output: 4

```

**Example 2:**

```
Input: piles = [30,11,23,4,20], h = 5
Output: 30

```

**Example 3:**

```
Input: piles = [30,11,23,4,20], h = 6
Output: 23

```

**Constraints:**

- `1 <= piles.length <= 10⁴`
- `piles.length <= h <= 10⁹`
- `1 <= piles[i] <= 10⁹`

*/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool Check(vector<int> &piles, int mid, int h) {
        long time = 0;
        for (int num : piles) {
            time += (num - 1) / mid + 1;
        }
        return time <= h;
    }
    int minEatingSpeed(vector<int> &piles, int h) {
        long sum = 0;
        for (int num : piles) {
            sum += num;
        }
        long left = 1;
        long right = sum + 10;
        while (left < right) {
            long mid = left + (right - left) / 2;
            if (!Check(piles, mid, h)) {
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

    vector<int> piles;
    LeetCodeIO::scan(cin, piles);
    int h;
    LeetCodeIO::scan(cin, h);

    Solution *obj = new Solution();

    auto res = obj->minEatingSpeed(piles, h);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
