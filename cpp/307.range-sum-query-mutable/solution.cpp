<<<<<<< HEAD
// Created by zwyyy456 at 2023/03/09 09:29
=======
// Created by zwyyy456 at 2023/03/09 23:21
>>>>>>> 2435687622386b4e03c7cd5907553e19cbc67e14
// https://leetcode.com/problems/range-sum-query-mutable/

/*
307. Range Sum Query - Mutable (Medium)

Given an integer array `nums`, handle multiple queries of the following types:

1. **Update** the value of an element in `nums`.
2. Calculate the **sum** of the elements of `nums` between indices `left` and `right` **inclusive**
where `left <= right`.

Implement the `NumArray` class:

- `NumArray(int[] nums)` Initializes the object with the integer array `nums`.
- `void update(int index, int val)` **Updates** the value of `nums[index]` to be `val`.
- `int sumRange(int left, int right)` Returns the **sum** of the elements of `nums` between indices
`left` and `right` **inclusive** (i.e. `nums[left] + nums[left + 1] + ... + nums[right]`).

**Example 1:**

```
Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8

```

**Constraints:**

- `1 <= nums.length <= 3 * 10⁴`
- `-100 <= nums[i] <= 100`
- `0 <= index < nums.length`
- `-100 <= val <= 100`
- `0 <= left <= right < nums.length`
- At most `3 * 10⁴` calls will be made to `update` and `sumRange`.
*/

// @lc code=begin
#include <vector>
using std::vector;
class NumArray {
  private:
    vector<int> arr;
    vector<int> prefix;
    vector<int> carr;
    int n;
    int Lowbit(int x) {
        return (x & -x);
    }
    int GetSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += carr[x];
            x -= Lowbit(x);
        }
        return sum;
    }

  public:
    NumArray(vector<int> &nums) {
        n = nums.size();
        arr.resize(n + 1);
        prefix.resize(n + 1);
        carr.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            arr[i] = nums[i - 1];
            prefix[i] = prefix[i - 1] + arr[i];
        }
        for (int i = 1; i <= n; ++i) {
            carr[i] = prefix[i] - prefix[i - Lowbit(i) + 1 - 1];
        }
    }

    void update(int index, int val) {
        int x = index + 1;
        while (x < n + 1) {
            carr[x] += val - arr[index + 1];
            x += Lowbit(x);
        }
        arr[index + 1] = val;
    }

    int sumRange(int left, int right) {
        return GetSum(right + 1) - GetSum(left);
    }
};

// @lc code=end
