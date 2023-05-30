// Created by zwyyy456 at 2023/05/23 09:22
// https://leetcode.com/problems/largest-values-from-labels/

/*
1090. Largest Values From Labels (Medium)
There is a set of `n` items. You are given two integer arrays `values` and `labels` where the value
and the label of the `ith` element are `values[i]` and `labels[i]` respectively. You are also given
two integers `numWanted` and `useLimit`.

Choose a subset `s` of the `n` elements such that:

- The size of the subset `s` is **less than or equal to** `numWanted`.
- There are **at most** `useLimit` items with the same label in `s`.

The **score** of a subset is the sum of the values in the subset.

Return the maximum **score** of a subset  `s`.

**Example 1:**

```
Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1
Output: 9
Explanation: The subset chosen is the first, third, and fifth items.

```

**Example 2:**

```
Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2
Output: 12
Explanation: The subset chosen is the first, second, and third items.

```

**Example 3:**

```
Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1
Output: 16
Explanation: The subset chosen is the first and fourth items.

```

**Constraints:**

- `n == values.length == labels.length`
- `1 <= n <= 2 * 10⁴`
- `0 <= values[i], labels[i] <= 2 * 10⁴`
- `1 <= numWanted, useLimit <= n`

*/

#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit) {
        unordered_map<int, int> cnt;
        priority_queue<pair<int, int>> pq;
        int n = values.size();
        for (int i = 0; i < n; ++i) {
            pq.push({values[i], labels[i]});
        }
        int num = 0;
        int res = 0;
        while (!pq.empty() && num < numWanted) {
            auto [val, label] = pq.top();
            pq.pop();
            if (cnt[label] < useLimit) {
                ++cnt[label];
                ++num;
                res += val;
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> values;
    LeetCodeIO::scan(cin, values);
    vector<int> labels;
    LeetCodeIO::scan(cin, labels);
    int numWanted;
    LeetCodeIO::scan(cin, numWanted);
    int useLimit;
    LeetCodeIO::scan(cin, useLimit);

    Solution *obj = new Solution();

    auto res = obj->largestValsFromLabels(values, labels, numWanted, useLimit);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
