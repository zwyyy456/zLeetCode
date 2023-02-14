// Created by Bob at 2023/02/14 09:26
// https://leetcode.com/problems/longest-well-performing-interval/

/*
1124. Longest Well-Performing Interval (Medium)

We are given `hours`, a list of the number of hours worked per day for a given employee.
A day is considered to be a tiring day if and only if the number of hours worked is (strictly)
greater than `8`.
A well-performing interval is an interval of days for which the number of tiring days is strictly
larger than the number of non-tiring days.
Return the length of the longest well-performing interval.
**Example 1:**
```
Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].
```
**Example 2:**
```
Input: hours = [6,6,6]
Output: 0
```
**Constraints:**
- `1 <= hours.length <= 10⁴`
- `0 <= hours[i] <= 16`
*/

// @lc code=begin
#include <functional>
#include <set>
#include <stack>
#include <vector>
#include <map>
using std::map;
using std::set;
using std::stack;
using std::vector;
class Solution {
  public:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    int longestWPI(vector<int> &hours) {
        int n = hours.size();
        // 大于8的转化为1，小于等于8的转化为-1
        for (auto &i : hours) {
            if (i > 8) {
                i = 1;
            } else {
                i = -1;
            }
        }
        // 计算新hours的前缀和
        vector<int> prefix(n, 0);
        prefix[0] = hours[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + hours[i];
        }
        map<int, int, std::greater<int>> mp; // 前缀相同时，保留下标最小的那个
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (prefix[i] > 0)
                res = max(res, i + 1);
            else {
                auto iter = mp.upper_bound(prefix[i]);
                // if (prefix[i] > mp.begin()->first) {
                //     res = max(res, i - mp.begin()->second);
                // }
                while (iter != mp.end()) {
                    res = max(res, i - mp.begin()->second);
                    iter++;
                }
                if (mp.find(prefix[i]) == mp.end()) {
                    mp[prefix[i]] = i;
                }
            }
        }
        return res;
    }
};

// @lc code=end
