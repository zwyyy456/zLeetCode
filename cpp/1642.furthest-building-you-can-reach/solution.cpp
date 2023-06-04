// Created by zwyyy456 at 2023/06/02 10:58
// https://leetcode.com/problems/furthest-building-you-can-reach/

/*
1642. Furthest Building You Can Reach (Medium)
You are given an integer array `heights` representing the heights of buildings, some `bricks`, and
some `ladders`.

You start your journey from building `0` and move to the next building by possibly using bricks or
ladders.

While moving from building `i` to building `i+1` ( **0-indexed**),

- If the current building's height is **greater than or equal** to the next building's height, you do
**not** need a ladder or bricks.
- If the current building's height is **less than** the next building's height, you can either use
**one ladder** or `(h[i+1] - h[i])` **bricks**.

Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks
optimally.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/27/q4.gif)

```
Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
Output: 4
Explanation: Starting at building 0, you can follow these steps:
- Go to building 1 without using ladders nor bricks since 4 >= 2.
- Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
- Go to building 3 without using ladders nor bricks since 7 >= 6.
- Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
It is impossible to go beyond building 4 because you do not have any more bricks or ladders.

```

**Example 2:**

```
Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
Output: 7

```

**Example 3:**

```
Input: heights = [14,3,19,3], bricks = 17, ladders = 0
Output: 3

```

**Constraints:**

- `1 <= heights.length <= 10⁵`
- `1 <= heights[i] <= 10⁶`
- `0 <= bricks <= 10⁹`
- `0 <= ladders <= heights.length`

*/

#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<>> pq;
        int n = heights.size();
        for (int i = 1; i < n; ++i) {
            if (heights[i] - heights[i - 1] > 0) {
                if (pq.size() < ladders) {
                    pq.push(heights[i] - heights[i - 1]);
                } else {
                    pq.push(heights[i] - heights[i - 1]);
                    bricks -= pq.top();
                    if (bricks < 0) {
                        return i - 1;
                    }
                    pq.pop();
                }
            }
        }
        return n - 1;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> heights;
    LeetCodeIO::scan(cin, heights);
    int bricks;
    LeetCodeIO::scan(cin, bricks);
    int ladders;
    LeetCodeIO::scan(cin, ladders);

    Solution *obj = new Solution();

    auto res = obj->furthestBuilding(heights, bricks, ladders);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
