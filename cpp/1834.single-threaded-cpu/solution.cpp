// Created by zwyyy456 at 2023/05/07 16:48
// https://leetcode.com/problems/single-threaded-cpu/

/*
1834. Single-Threaded CPU (Medium)
You are given `n`  tasks labeled from `0` to `n - 1` represented by a 2D integer array `tasks`, where
`tasks[i] = [enqueueTimeᵢ, processingTimeᵢ]` means that the `ith`  task will be available to process
at `enqueueTimeᵢ` and will take `processingTimeᵢ` to finish processing.

You have a single-threaded CPU that can process **at most one** task at a time and will act in the
following way:

- If the CPU is idle and there are no available tasks to process, the CPU remains idle.
- If the CPU is idle and there are available tasks, the CPU will choose the one with the **shortest
processing time**. If multiple tasks have the same shortest processing time, it will choose the task
with the smallest index.
- Once a task is started, the CPU will **process the entire task** without stopping.
- The CPU can finish a task then start a new one instantly.

Return the order in which the CPU will process the tasks.

**Example 1:**

```
Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]
Explanation: The events go as follows:
- At time = 1, task 0 is available to process. Available tasks = {0}.
- Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
- At time = 2, task 1 is available to process. Available tasks = {1}.
- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest.
Available tasks = {1}.
- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
- At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available
tasks = {1}.
- At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
- At time = 10, the CPU finishes task 1 and becomes idle.

```

**Example 2:**

```
Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
Output: [4,3,2,0,1]
Explanation: The events go as follows:
- At time = 7, all the tasks become available. Available tasks = {0,1,2,3,4}.
- Also at time = 7, the idle CPU starts processing task 4. Available tasks = {0,1,2,3}.
- At time = 9, the CPU finishes task 4 and starts processing task 3. Available tasks = {0,1,2}.
- At time = 13, the CPU finishes task 3 and starts processing task 2. Available tasks = {0,1}.
- At time = 18, the CPU finishes task 2 and starts processing task 0. Available tasks = {1}.
- At time = 28, the CPU finishes task 0 and starts processing task 1. Available tasks = {}.
- At time = 40, the CPU finishes task 1 and becomes idle.

```

**Constraints:**

- `tasks.length == n`
- `1 <= n <= 10⁵`
- `1 <= enqueueTimeᵢ, processingTimeᵢ <= 10⁹`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> getOrder(vector<vector<int>> &tasks) {
        int n = tasks.size();
        vector<int> index(n);
        for (int i = 0; i < n; ++i) {
            index[i] = i;
        }
        std::sort(index.begin(), index.end(), [&tasks](int id1, int id2) {
            if (tasks[id1][0] == tasks[id2][0]) {
                return tasks[id1][1] < tasks[id2][1];
            }
            return tasks[id1][0] < tasks[id2][0];
        });
        std::sort(tasks.begin(), tasks.end());

        auto cmp = [&tasks, &index](int id1, int id2) {
            if (tasks[id1][1] == tasks[id2][1]) {
                return index[id1] > index[id2];
            }
            return tasks[id1][1] > tasks[id2][1];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        pq.push(0);
        int start_idx = 1;
        // 二分找第一个大于等于当前时间的 idx
        vector<int> res;
        long cur_time = 0;
        while (!pq.empty()) {
            int idx = pq.top();
            res.push_back(index[idx]);
            pq.pop();
            cur_time = max((max(cur_time, (long)tasks[idx][0]) + tasks[idx][1]), (long)tasks[idx + 1 < n ? idx + 1 : idx][0]);
            if (start_idx >= n) {
                continue;
            }
            for (int i = start_idx; i < n && tasks[i][0] <= cur_time;) {
                pq.push(i);
                start_idx = ++i;
                // cout << "i = " << i << endl;
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> tasks;
    LeetCodeIO::scan(cin, tasks);

    Solution *obj = new Solution();

    auto res = obj->getOrder(tasks);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
