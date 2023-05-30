// Created by zwyyy456 at 2023/05/23 09:54
// https://leetcode.com/problems/range-sum-query-immutable/

/*
303. Range Sum Query - Immutable (Easy)
Given an integer array `nums`, handle multiple queries of the following type:

1. Calculate the **sum** of the elements of `nums` between indices `left` and `right` **inclusive**
where `left <= right`.

Implement the `NumArray` class:

- `NumArray(int[] nums)` Initializes the object with the integer array `nums`.
- `int sumRange(int left, int right)` Returns the **sum** of the elements of `nums` between indices
`left` and `right` **inclusive** (i.e. `nums[left] + nums[left + 1] + ... + nums[right]`).

**Example 1:**

```
Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

```

**Constraints:**

- `1 <= nums.length <= 10⁴`
- `-10⁵ <= nums[i] <= 10⁵`
- `0 <= left <= right < nums.length`
- At most `10⁴` calls will be made to `sumRange`.

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class NumArray {
  public:
    NumArray(vector<int> &nums) :
        prefix(nums.size() + 1) {
        for (int i = 1; i <= nums.size(); ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }

  private:
    vector<int> prefix;
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    NumArray *obj;

    const unordered_map<string, function<void()>> methods = {
        {"NumArray", [&]() {
             vector<int> nums;
             LeetCodeIO::scan(cin, nums);
             cin.ignore();
             int numsSize;
             LeetCodeIO::scan(cin, numsSize);
             cin.ignore();
             obj = new NumArray(nums, numsSize);
             out_stream << "null,";
         }},
        {"sumRange", [&]() {
             int left;
             LeetCodeIO::scan(cin, left);
             cin.ignore();
             int right;
             LeetCodeIO::scan(cin, right);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->sumRange(left, right));
             out_stream << ',';
         }},
    };
    out_stream << '[';
    for (auto &&method_name : method_names) {
        cin.ignore(2);
        methods.at(method_name)();
    }
    cin.ignore();
    out_stream.seekp(-1, ios_base::end);
    out_stream << ']';

    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
