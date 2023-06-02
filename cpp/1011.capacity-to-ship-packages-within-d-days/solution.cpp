// Created by zwyyy456 at 2023/06/01 12:12
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

/*
1011. Capacity To Ship Packages Within D Days (Medium)
A conveyor belt has packages that must be shipped from one port to another within `days` days.

The `ith` package on the conveyor belt has a weight of `weights[i]`. Each day, we load the ship with
packages on the conveyor belt (in the order given by `weights`). We may not load more weight than
the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor
belt being shipped within `days` days.

**Example 1:**

```
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting
the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

```

**Example 2:**

```
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4

```

**Example 3:**

```
Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1

```

**Constraints:**

- `1 <= days <= weights.length <= 5 * 10⁴`
- `1 <= weights[i] <= 500`

*/

#include <bits/stdc++.h>
#include <numeric>
#include <regex>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int Bfind(vector<int> &prefix, int l, int amount) {
        int left = l, right = prefix.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefix[mid] - prefix[l] < amount + 1) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
    bool Check(vector<int> &prefix, int days, int mid) {
        int l = 0, r = 0;
        int cnt = 0;
        while (r < prefix.size() - 1 && cnt <= days + 1) {
            r = Bfind(prefix, l, mid);
            l = r;
            ++cnt;
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int> &weights, int days) {
        int left = 1, right = accumulate(weights.begin(), weights.end(), 0);
        vector<int> prefix(weights.size() + 1);
        for (int i = 1; i <= weights.size(); ++i) {
            prefix[i] = prefix[i - 1] + weights[i - 1];
            left = max(left, weights[i - 1]);
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (!Check(prefix, days, mid)) {
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

    vector<int> weights;
    LeetCodeIO::scan(cin, weights);
    int days;
    LeetCodeIO::scan(cin, days);

    Solution *obj = new Solution();

    auto res = obj->shipWithinDays(weights, days);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
