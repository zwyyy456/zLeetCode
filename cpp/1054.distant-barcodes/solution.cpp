// Created by zwyyy456 at 2023/05/14 14:15
// https://leetcode.com/problems/distant-barcodes/

/*
1054. Distant Barcodes (Medium)
In a warehouse, there is a row of barcodes, where the `ith` barcode is `barcodes[i]`.

Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it
is guaranteed an answer exists.

**Example 1:**

```
Input: barcodes = [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]

```

**Example 2:**

```
Input: barcodes = [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,1,2,1,2]

```

**Constraints:**

- `1 <= barcodes.length <= 10000`
- `1 <= barcodes[i] <= 10000`

*/

#include <bits/stdc++.h>
#include <queue>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
class Solution {
  public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes) {
        unordered_map<int, int> codes;
        for (auto num : barcodes) {
            ++codes[num];
        }
        auto cmp = [&codes](int i, int j) {
            return codes[i] < codes[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (auto &code : codes) {
            // cout << code.first << endl;
            pq.push(code.first);
        }
        int n = barcodes.size();
        vector<int> res(n);
        res[0] = pq.top();
        --codes[res[0]];
        for (int i = 1; i < n; ++i) {
            auto num1 = pq.top();
            if (num1 != res[i - 1]) {
                res[i] = num1;
                --codes[num1];
            } else {
                pq.pop();
                int num2 = 0;
                if (!pq.empty()) {
                    num2 = pq.top();
                    // cout << "right" << endl;
                }
                res[i] = num2;
                pq.push(num1);
                --codes[num2];
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> barcodes;
    LeetCodeIO::scan(cin, barcodes);

    Solution *obj = new Solution();

    auto res = obj->rearrangeBarcodes(barcodes);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
