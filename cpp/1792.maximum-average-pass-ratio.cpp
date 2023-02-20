// Created by zwyyy456 at 2023/02/19 21:58
// https://leetcode.com/problems/maximum-average-pass-ratio/

/*
1792. Maximum Average Pass Ratio (Medium)

There is a school that has classes of students and each class will be having a final exam. You are
given a 2D integer array `classes`, where `classes[i] = [passᵢ, totalᵢ]`. You know beforehand that
in the `ith` class, there are `totalᵢ` total students, but only `passᵢ` number of students will pass
the exam.

You are also given an integer `extraStudents`. There are another `extraStudents` brilliant students
that are **guaranteed** to pass the exam of any class they are assigned to. You want to assign each
of the `extraStudents` students to a class in a way that **maximizes** the **average** pass ratio
across **all** the classes.

The **pass ratio** of a class is equal to the number of students of the class that will pass the
exam divided by the total number of students of the class. The **average pass ratio** is the sum of
pass ratios of all the classes divided by the number of the classes.

Return the **maximum** possible average pass ratio after assigning the  `extraStudents` students.
Answers within `10-⁵` of the actual answer will be accepted.

**Example 1:**

```
Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333
Explanation: You can assign the two extra students to the first class. The average pass ratio will
be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.

```

**Example 2:**

```
Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485

```

**Constraints:**

- `1 <= classes.length <= 10⁵`
- `classes[i].length == 2`
- `1 <= passᵢ <= totalᵢ <= 10⁵`
- `1 <= extraStudents <= 10⁵`
*/

// @lc code=begin
#include <vector>
#include <queue>
using std::queue;
using std::vector;
class Solution {
  public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
        auto cmp = [&](int a, int b) {
            return (double)(classes[a][1] - classes[a][0]) / (classes[a][1] * classes[a][1] + classes[a][1]) > (double)(classes[b][1] - classes[b][0]) / (classes[b][1] * classes[b][1] + classes[b][1]);
        };
        std::priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < classes.size(); i++) {
            pq.push(i);
        }
        for (int num = 1; num <= extraStudents; num++) {
            int idx = pq.top();
            pq.pop();
            classes[idx][0] += 1;
            classes[idx][1] += 1;
        }
    }
};

// @lc code=end
