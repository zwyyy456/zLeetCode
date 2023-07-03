// Created by zwyyy456 at 2023/03/07 13:45
// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/

/*
497. Random Point in Non-overlapping Rectangles (Medium)

You are given an array of non-overlapping axis-aligned rectangles `rects` where `rects[i] = [aᵢ, bᵢ,
xᵢ, yᵢ]` indicates that `(aᵢ, bᵢ)` is the bottom-left corner point of the `ith` rectangle and `(xᵢ,
yᵢ)` is the top-right corner point of the `ith` rectangle. Design an algorithm to pick a random
integer point inside the space covered by one of the given rectangles. A point on the perimeter of a
rectangle is included in the space covered by the rectangle.

Any integer point inside the space covered by one of the given rectangles should be equally likely
to be returned.

**Note** that an integer point is a point that has integer coordinates.

Implement the `Solution` class:

- `Solution(int[][] rects)` Initializes the object with the given rectangles `rects`.
- `int[] pick()` Returns a random integer point `[u, v]` inside the space covered by one of the
given rectangles.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/07/24/lc-pickrandomrec.jpg)

```
Input
["Solution", "pick", "pick", "pick", "pick", "pick"]
[[[[-2, -2, 1, 1], [2, 2, 4, 6]]], [], [], [], [], []]
Output
[null, [1, -2], [1, -1], [-1, -2], [-2, -2], [0, 0]]

Explanation
Solution solution = new Solution([[-2, -2, 1, 1], [2, 2, 4, 6]]);
solution.pick(); // return [1, -2]
solution.pick(); // return [1, -1]
solution.pick(); // return [-1, -2]
solution.pick(); // return [-2, -2]
solution.pick(); // return [0, 0]

```

**Constraints:**

- `1 <= rects.length <= 100`
- `rects[i].length == 4`
- `-10⁹ <= aᵢ < xᵢ <= 10⁹`
- `-10⁹ <= bᵢ < yᵢ <= 10⁹`
- `xᵢ - aᵢ <= 2000`
- `yᵢ - bᵢ <= 2000`
- All the rectangles do not overlap.
- At most `10⁴` calls will be made to `pick`.
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  private:
    int total_num = 0;
    int pick_num = 0;
    vector<vector<int>> rectangles;
    vector<int> points_num;
    int BSearch(int target) {
        int left = 0, right = points_num.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (points_num[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

  public:
    Solution(vector<vector<int>> &rects) {
        points_num.push_back(0);
        for (auto &vec : rects) {
            rectangles.push_back(vec);
            total_num += (vec[2] - vec[0] + 1) * (vec[3] - vec[1] + 1);
            points_num.push_back(total_num);
        }
    }
    vector<int> pick() {
        int choose = pick_num % total_num;
        int idx = BSearch(choose + 1) - 1;                                  // 选择索引为idx的矩形
        choose -= points_num[idx];                                          // 从索引为idx的矩形的索引为choose的点
        int x_idx = choose % (rectangles[idx][2] - rectangles[idx][0] + 1); // 对矩形的长取模
        int y_idx = choose / (rectangles[idx][2] - rectangles[idx][0] + 1);
        pick_num++;
        return {x_idx + rectangles[idx][0], y_idx + rectangles[idx][1]};
    }
};

// @lc code=end
