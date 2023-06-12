// Created by zwyyy456 at 2023/06/07 09:11
// https://leetcode.com/problems/mice-and-cheese/

/*
2611. Mice and Cheese (Medium)
There are two mice and `n` different types of cheese, each type of cheese should be eaten by exactly
one mouse.

A point of the cheese with index `i` ( **0-indexed**) is:

- `reward1[i]` if the first mouse eats it.
- `reward2[i]` if the second mouse eats it.

You are given a positive integer array `reward1`, a positive integer array `reward2`, and a non-
negative integer `k`.

Return **the maximum** points the mice can achieve if the first mouse eats exactly  `k` types of
cheese.

**Example 1:**

```
Input: reward1 = [1,1,3,4], reward2 = [4,4,1,1], k = 2
Output: 15
Explanation: In this example, the first mouse eats the 2ⁿd (0-indexed) and the 3rd types of cheese,
and the second mouse eats the 0th and the 1st types of cheese.
The total points are 4 + 4 + 3 + 4 = 15.
It can be proven that 15 is the maximum total points that the mice can achieve.

```

**Example 2:**

```
Input: reward1 = [1,1], reward2 = [1,1], k = 2
Output: 2
Explanation: In this example, the first mouse eats the 0th (0-indexed) and 1st types of cheese, and
the second mouse does not eat any cheese.
The total points are 1 + 1 = 2.
It can be proven that 2 is the maximum total points that the mice can achieve.

```

**Constraints:**

- `1 <= n == reward1.length == reward2.length <= 10⁵`
- `1 <= reward1[i], reward2[i] <= 1000`
- `0 <= k <= n`

*/

#include <bits/stdc++.h>
#include <functional>
#include <numeric>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k) {
        int sum2 = 0, n = reward1.size();
        for (int rew : reward2) {
            sum2 += rew;
        }
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = reward1[i] - reward2[i];
        }
        sort(nums.begin(), nums.end(), greater<>());
        for (int i = 0; i < k; ++i) {
            sum2 += nums[i];
        }
        return sum2;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> reward1;
    LeetCodeIO::scan(cin, reward1);
    vector<int> reward2;
    LeetCodeIO::scan(cin, reward2);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();

    auto res = obj->miceAndCheese(reward1, reward2, k);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
