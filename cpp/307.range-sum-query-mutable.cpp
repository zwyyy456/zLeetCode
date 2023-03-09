// Created by zwyyy456 at 2023/03/09 09:29
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
    vector<int> carr;
    int Lowbit(int x) {
        return x ^ -x;
    }
    int GetPrefix(int right) {
        int ans = 0;
        while (right > 0) {
            ans += carr[right];
            right -= Lowbit(right);
        }
        return ans;
    }

  public:
    NumArray(vector<int> &nums) {
        arr.resize(nums.size() + 1);
        carr.resize(nums.size() + 1);
        vector<int> prefix(nums.size() + 1);
        for (int i = 1; i <= nums.size(); ++i) {
            arr[i] = nums[i - 1];
            prefix[i] = prefix[i - 1] + arr[i];
        }
        for (int i = 1; i <= nums.size(); ++i) {
            carr[i] = prefix[i] - prefix[i - Lowbit(i)];
        }
    }

    void update(int index, int val) {
    }

    int sumRange(int left, int right) {
    }
};

// @lc code=end
