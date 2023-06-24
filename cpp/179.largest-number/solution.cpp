// Created by zwyyy456 at 2023/02/28 09:28
// https://leetcode.com/problems/largest-number/

/*
179. Largest Number (Medium)

Given a list of non-negative integers `nums`, arrange them such that they form the largest number
and return it.

Since the result may be very large, so you need to return a string instead of an integer.

**Example 1:**

```
Input: nums = [10,2]
Output: "210"

```

**Example 2:**

```
Input: nums = [3,30,34,5,9]
Output: "9534330"

```

**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 10⁹`
*/

// @lc code=begin
#include <vector>
#include <string>
using std::string;
using std::vector;
class Solution {
  public:
    string largestNumber(vector<int> &nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                sum += nums[i];
                break;
            }
        }
        if (sum == 0) {
            return "0";
        }
        vector<string> tmp;
        for (int &num : nums) {
            tmp.push_back(std::to_string(num));
        }

        auto cmp = [&](string &s1, string &s2) {
            return s2 + s1 <= s1 + s2;
        };
        std::sort(tmp.begin(), tmp.end(), cmp);
        string res;
        for (auto &s : tmp) {
            res += s;
        }
        return res;
    }
};

// @lc code=end
