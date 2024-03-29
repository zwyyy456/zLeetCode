// Created by zwyyy456 at 2023/05/07 14:28
// https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/
// https://leetcode.com/contest/weekly-contest-344/problems/number-of-adjacent-elements-with-the-same-color/

/*
2672. Number of Adjacent Elements With the Same Color (Medium)
There is a **0-indexed** array `nums` of length `n`. Initially, all elements are **uncolored**(has a
value of `0`).

You are given a 2D integer array `queries` where `queries[i] = [indexᵢ, colorᵢ]`.

For each query, you color the index `indexᵢ` with the color `colorᵢ` in the array `nums`.

Return an array  `answer` of the same length as  `queries` where  `answer[i]` is the number of
adjacent elements with the same color **after** the  `ith` query.

More formally, `answer[i]` is the number of indices `j`, such that `0 <= j < n - 1` and `nums[j] ==
nums[j + 1]` and `nums[j] != 0` after the `ith` query.

**Example 1:**

```
Input: n = 4, queries = [[0,2],[1,2],[3,1],[1,1],[2,1]]
Output: [0,1,1,0,2]
Explanation: Initially array nums = [0,0,0,0], where 0 denotes uncolored elements of the array.
- After the 1st query nums = [2,0,0,0]. The count of adjacent elements with the same color is 0.
- After the 2ⁿd query nums = [2,2,0,0]. The count of adjacent elements with the same color is 1.
- After the 3rd query nums = [2,2,0,1]. The count of adjacent elements with the same color is 1.
- After the 4th query nums = [2,1,0,1]. The count of adjacent elements with the same color is 0.
- After the 5th query nums = [2,1,1,1]. The count of adjacent elements with the same color is 2.

```

**Example 2:**

```
Input: n = 1, queries = [[0,100000]]
Output: [0]
Explanation: Initially array nums = [0], where 0 denotes uncolored elements of the array.
- After the 1st query nums = [100000]. The count of adjacent elements with the same color is 0.

```

**Constraints:**

- `1 <= n <= 10⁵`
- `1 <= queries.length <= 10⁵`
- `queries[i].length == 2`
- `0 <= indexᵢ <= n - 1`
- `1 <=  colorᵢ <= 10⁵`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> colorTheArray(int n, vector<vector<int>> &queries) {
        int times = queries.size();
        vector<int> ans(times + 1);
        vector<int> nums(n);

        for (int i = 1; i <= times; ++i) {
            int idx = queries[i - 1][0];
            int color = queries[i - 1][1];
            int pre_color = nums[idx];
            nums[idx] = color;
            ans[i] = ans[i - 1];
            if (idx > 0 && pre_color == nums[idx - 1] && pre_color != 0) {
                --ans[i];
            }
            if (idx < n - 1 && pre_color == nums[idx + 1] && pre_color != 0) {
                --ans[i];
            }
            if (idx > 0 && color == nums[idx - 1] && color != 0) {
                ++ans[i];
            }
            if (idx < n - 1 && color == nums[idx + 1] && color != 0) {
                ++ans[i];
            }
        }
        return vector<int>(ans.begin() + 1, ans.end());
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    vector<vector<int>> queries;
    LeetCodeIO::scan(cin, queries);

    Solution *obj = new Solution();

    auto res = obj->colorTheArray(n, queries);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
