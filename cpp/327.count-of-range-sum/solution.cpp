// Created by zwyyy456 at 2023/03/11 12:13
// https://leetcode.com/problems/count-of-range-sum/

/*
327. Count of Range Sum (Hard)

Given an integer array `nums` and two integers `lower` and `upper`, return the number of range sums
that lie in `[lower, upper]`inclusive.

Range sum `S(i, j)` is defined as the sum of the elements in `nums` between indices `i` and `j`
inclusive, where `i <= j`.

**Example 1:**

```
Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3
Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.

```

**Example 2:**

```
Input: nums = [0], lower = 0, upper = 0
Output: 1

```

**Constraints:**

- `1 <= nums.length <= 10⁵`
- `-2³¹ <= nums[i] <= 2³¹ - 1`
- `-10⁵ <= lower <= upper <= 10⁵`
- The answer is **guaranteed** to fit in a **32-bit** integer.
*/
#include <vector>
using std::vector;
// @lc code=begin
class Solution {
  public:
    int countRangeSumRecursive(vector<long> &sum, int lower, int upper, int left, int right) {
        if (left == right) {
            return 0;
        } else {
            int mid = (left + right) / 2;
            int n1 = countRangeSumRecursive(sum, lower, upper, left, mid);
            int n2 = countRangeSumRecursive(sum, lower, upper, mid + 1, right);
            int ret = n1 + n2;

            // 首先统计下标对的数量
            int i = left;
            int l = mid + 1;
            int r = mid + 1;
            while (i <= mid) {
                while (l <= right && sum[l] - sum[i] < lower) l++;
                while (r <= right && sum[r] - sum[i] <= upper) r++;
                ret += (r - l);
                i++;
            }

            // 随后合并两个排序数组
            vector<long> sorted(right - left + 1);
            int p1 = left, p2 = mid + 1;
            int p = 0;
            while (p1 <= mid || p2 <= right) {
                if (p1 > mid) {
                    sorted[p++] = sum[p2++];
                } else if (p2 > right) {
                    sorted[p++] = sum[p1++];
                } else {
                    if (sum[p1] < sum[p2]) {
                        sorted[p++] = sum[p1++];
                    } else {
                        sorted[p++] = sum[p2++];
                    }
                }
            }
            for (int i = 0; i < sorted.size(); i++) {
                sum[left + i] = sorted[i];
            }
            return ret;
        }
    }

    int countRangeSum(vector<int> &nums, int lower, int upper) {
        long s = 0;
        vector<long> sum{0};
        for (auto &v : nums) {
            s += v;
            sum.push_back(s);
        }
        return countRangeSumRecursive(sum, lower, upper, 0, sum.size() - 1);
    }
};

// @lc code=end
