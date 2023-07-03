// Created by Bob at 2023/02/13 14:18
// https://leetcode.com/problems/super-washing-machines/

/*
517. Super Washing Machines (Hard)

You have `n` super washing machines on a line. Initially, each washing machine has some dresses or
is empty.
For each move, you could choose any `m` ( `1 <= m <= n`) washing machines, and pass one dress of
each washing machine to one of its adjacent washing machines at the same time.
Given an integer array `machines` representing the number of dresses in each washing machine from
left to right on the line, return the minimum number of moves to make all the washing machines have
the same number of dresses. If it is not possible to do it, return `-1`.
**Example 1:**
```
Input: machines = [1,0,5]
Output: 3
Explanation:
1st move:    1     0 <-- 5    =>    1     1     4
2nd move:    1 <-- 1 <-- 4    =>    2     1     3
3rd move:    2     1 <-- 3    =>    2     2     2
```
**Example 2:**
```
Input: machines = [0,3,0]
Output: 2
Explanation:
1st move:    0 <-- 3     0    =>    1     2     0
2nd move:    1     2 --> 0    =>    1     1     1
```
**Example 3:**
```
Input: machines = [0,2,0]
Output: -1
Explanation:
It's impossible to make all three washing machines have the same number of dresses.
```
**Constraints:**
- `n == machines.length`
- `1 <= n <= 10⁴`
- `0 <= machines[i] <= 10⁵`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    int LowerBound(vector<int> &vec, int target) {
        int l = 0, r = vec.size();
        int mid = (l + r) / 2;
        while (l < r) {
            if (vec[mid] >= target) {
                r = mid;
            } else {
                l = mid;
            }
            mid = l + (r - l) / 2;
        }
        return l;
    }
    int findMinMoves(vector<int> &machines) {
        int sum = 0, n = machines.size();
        for (auto i : machines) {
            sum += i;
        }
        if (sum % n != 0)
            return -1;
        std::sort(machines.begin(), machines.end());
        int avg = sum / n;
        int cnt = 0;
        int l = LowerBound(machines, avg) - 1;
        int r = LowerBound(machines, avg + 1);
        while (l >= 0 && r < machines.size()) {
            cnt++;
            machines[r]--;
            if (machines[r] <= avg)
                r++;
            machines[l]++;
            if (machines[l] >= avg)
                l--;
        }
        return cnt;
    }
};

// @lc code=end
