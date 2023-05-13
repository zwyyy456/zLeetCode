// Created by zwyyy456 at 2023/05/02 11:29
// https://leetcode.com/problems/time-needed-to-inform-all-employees/

/*
1376. Time Needed to Inform All Employees (Medium)
A company has `n` employees with a unique ID for each employee from `0` to `n - 1`. The head of the
company is the one with `headID`.

Each employee has one direct manager given in the `manager` array where `manager[i]` is the direct
manager of the `i-th` employee, `manager[headID] = -1`. Also, it is guaranteed that the subordination
relationships have a tree structure.

The head of the company wants to inform all the company employees of an urgent piece of news. He
will inform his direct subordinates, and they will inform their subordinates, and so on until all
employees know about the urgent news.

The `i-th` employee needs `informTime[i]` minutes to inform all of his direct subordinates (i.e.,
After informTime\[i\] minutes, all his direct subordinates can start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent news.

**Example 1:**

```
Input: n = 1, headID = 0, manager = [-1], informTime = [0]
Output: 0
Explanation: The head of the company is the only employee in the company.

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/02/27/graph.png)

```
Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
Output: 1
Explanation: The head of the company with id = 2 is the direct manager of all the employees in the
company and needs 1 minute to inform them all.
The tree structure of the employees in the company is shown.

```

**Constraints:**

- `1 <= n <= 10⁵`
- `0 <= headID < n`
- `manager.length == n`
- `0 <= manager[i] < n`
- `manager[headID] == -1`
- `informTime.length == n`
- `0 <= informTime[i] <= 1000`
- `informTime[i] == 0` if employee `i` has no subordinates.
- It is **guaranteed** that all the employees can be informed.

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
        vector<vector<int>> graph(n);
        int ceoid = 0;
        for (int i = 0; i < n; ++i) {
            int man = manager[i];
            if (man == -1) {
                ceoid = i;
                continue;
            }
            graph[man].push_back(i);
        }
        int res = 0;
        queue<pair<int, int>> infoq; // 时间，以及 id
        infoq.push({res, ceoid});
        while (!infoq.empty()) {
            // int siz = infoq.size();
            // for (int i = 0; i < siz; ++i)
            auto [dis, idx] = infoq.front();
            res = max(res, dis);
            infoq.pop();
            for (int person : graph[idx]) {
                infoq.push({dis + informTime[idx], person});
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    int headID;
    LeetCodeIO::scan(cin, headID);
    vector<int> manager;
    LeetCodeIO::scan(cin, manager);
    vector<int> informTime;
    LeetCodeIO::scan(cin, informTime);

    Solution *obj = new Solution();

    auto res = obj->numOfMinutes(n, headID, manager, informTime);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
