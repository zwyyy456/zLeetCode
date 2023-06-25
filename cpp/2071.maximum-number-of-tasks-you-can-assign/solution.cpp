// Created by zwyyy456 at 2023/03/22 15:40
// https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/

/*
2071. Maximum Number of Tasks You Can Assign (Hard)

You have `n` tasks and `m` workers. Each task has a strength requirement stored in a **0-indexed**
integer array `tasks`, with the `ith` task requiring `tasks[i]` strength to complete. The strength
of each worker is stored in a **0-indexed** integer array `workers`, with the `jth` worker having
`workers[j]` strength. Each worker can only be assigned to a **single** task and must have a
strength **greater than or equal** to the task's strength requirement (i.e., `workers[j] >=
tasks[i]`).

Additionally, you have `pills` magical pills that will **increase a worker's strength** by
`strength`. You can decide which workers receive the magical pills, however, you may only give each
worker **at most one** magical pill.

Given the **0-indexed** integer arrays `tasks` and `workers` and the integers `pills` and
`strength`, return the **maximum** number of tasks that can be completed.

**Example 1:**

```
Input: tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
Output: 3
Explanation:
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 2 (0 + 1 >= 1)
- Assign worker 1 to task 1 (3 >= 2)
- Assign worker 2 to task 0 (3 >= 3)

```

**Example 2:**

```
Input: tasks = [5,4], workers = [0,0,0], pills = 1, strength = 5
Output: 1
Explanation:
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 0 (0 + 5 >= 5)

```

**Example 3:**

```
Input: tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, strength = 10
Output: 2
Explanation:
We can assign the magical pills and tasks as follows:
- Give the magical pill to worker 0 and worker 1.
- Assign worker 0 to task 0 (0 + 10 >= 10)
- Assign worker 1 to task 1 (10 + 10 >= 15)
The last pill is not given because it will not make any worker strong enough for the last task.

```

**Constraints:**

- `n == tasks.length`
- `m == workers.length`
- `1 <= n, m <= 5 * 10⁴`
- `0 <= pills <= m`
- `0 <= tasks[i], workers[j], strength <= 10⁹`
*/

// @lc code=begin
#include <vector>
#include <algorithm>
#include <map>
using std::map;
using std::vector;
class Solution {
  public:
    bool check(int num, vector<int> &tasks, vector<int> &workers, int pills, map<int, int> mp, int strength) {
        for (int i = 0, j = workers.size() - num; i < tasks.size() && j < workers.size(); ++i, ++j) {
            if (mp.begin()->first > workers[j]) {
                if (pills <= 0) {
                    return false;
                } else {
                    if (mp.begin()->first > strength + workers[j]) {
                        return false;
                    } else {
                        auto iter = mp.lower_bound(strength + workers[j]);
                        if (iter->first == strength + workers[j]) {
                            --iter->second;
                            if (iter->second == 0) {
                                mp.erase(iter);
                            }
                        } else {
                            --iter;
                            --iter->second;
                            if (iter->second == 0) {
                                mp.erase(iter);
                            }
                        }
                        --pills;
                    }
                }
            } else {
                mp.begin()->second--;
                if (mp.begin()->second == 0) {
                    mp.erase(mp.begin());
                }
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength) {
        // 对工人的力量值从小到大排序
        // 对任务的所需力量值从小到大排序
        // 二分+贪心
        int m = std::min(workers.size(), tasks.size());
        std::sort(tasks.begin(), tasks.end());
        std::sort(workers.begin(), workers.end());
        map<int, int> mp;
        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        int left = 0, right = m;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid, tasks, workers, pills, mp, strength)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (check(left, tasks, workers, pills, mp, strength))
            return left;
        return left - 1;
    }
};

// @lc code=end
