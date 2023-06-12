// Created by zwyyy456 at 2023/06/01 10:49
// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

/*
2226. Maximum Candies Allocated to K Children (Medium)
You are given a **0-indexed** integer array `candies`. Each element in the array denotes a pile of
candies of size `candies[i]`. You can divide each pile into any number of **sub piles**, but you
**cannot** merge two piles together.

You are also given an integer `k`. You should allocate piles of candies to `k` children such that
each child gets the **same** number of candies. Each child can take **at most one** pile of candies
and some piles of candies may go unused.

Return the **maximum number of candies** each child can get.

**Example 1:**

```
Input: candies = [5,8,6], k = 3
Output: 5
Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of
size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3
piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.

```

**Example 2:**

```
Input: candies = [2,5], k = 11
Output: 0
Explanation: There are 11 children but only 7 candies in total, so it is impossible to ensure each
child receives at least one candy. Thus, each child gets no candy and the answer is 0.

```

**Constraints:**

- `1 <= candies.length <= 10⁵`
- `1 <= candies[i] <= 10⁷`
- `1 <= k <= 10¹²`

*/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool Check(vector<int> &candies, long mid, long k) {
        long cnt = 0;
        for (int num : candies) {
            cnt += num / mid;
        }
        return cnt >= k;
    }
    int maximumCandies(vector<int> &candies, long long k) {
        long sum = 0;
        for (int num : candies) {
            sum += num;
        }
        long left = 1, right = sum + 10;
        cout << sum << endl;
        while (left < right) {
            long mid = left + (right - left) / 2;
            if (Check(candies, mid, k)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> candies;
    LeetCodeIO::scan(cin, candies);
    int64_t k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();

    auto res = obj->maximumCandies(candies, k);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
