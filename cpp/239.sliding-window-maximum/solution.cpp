// Created by zwyyy456 at 2023/05/20 19:19
// https://leetcode.com/problems/sliding-window-maximum/

/*
239. Sliding Window Maximum (Hard)
You are given an array of integers `nums`, there is a sliding window of size `k` which is moving
from the very left of the array to the very right. You can only see the `k` numbers in the window.
Each time the sliding window moves right by one position.

Return the max sliding window.

**Example 1:**

```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

```

**Example 2:**

```
Input: nums = [1], k = 1
Output: [1]

```

**Constraints:**

- `1 <= nums.length <= 10⁵`
- `-10⁴ <= nums[i] <= 10⁴`
- `1 <= k <= nums.length`

*/

#include <bits/stdc++.h>
#include <functional>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // map
        map<int, int, greater<int>> cntk;
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            ++cntk[nums[i]];
        }
        res.push_back(cntk.begin()->first);
        for (int i = k; i < nums.size(); ++i) {
            --cntk[nums[i - k]];
            if (cntk[nums[i - k]] == 0) {
                cntk.erase(nums[i - k]);
            }
            ++cntk[nums[i]];
            res.push_back(cntk.begin()->first);
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();

    auto res = obj->maxSlidingWindow(nums, k);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
