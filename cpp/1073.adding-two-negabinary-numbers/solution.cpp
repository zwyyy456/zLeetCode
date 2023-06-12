// Created by zwyyy456 at 2023/05/18 09:22
// https://leetcode.com/problems/adding-two-negabinary-numbers/

/*
1073. Adding Two Negabinary Numbers (Medium)
Given two numbers `arr1` and `arr2` in base **-2**, return the result of adding them together.

Each number is given in array format:  as an array of 0s and 1s, from most significant bit to least
significant bit.  For example, `arr = [1,1,0,1]` represents the number `(-2)^3 + (-2)^2 + (-2)^0 = -3`.
A number `arr` in array, format is also guaranteed to have no leading zeros: either `arr == [0]` or
`arr[0] == 1`.

Return the result of adding `arr1` and `arr2` in the same format: as an array of 0s and 1s with no
leading zeros.

**Example 1:**

```
Input: arr1 = [1,1,1,1,1], arr2 = [1,0,1]
Output: [1,0,0,0,0]
Explanation: arr1 represents 11, arr2 represents 5, the output represents 16.

```

**Example 2:**

```
Input: arr1 = [0], arr2 = [0]
Output: [0]

```

**Example 3:**

```
Input: arr1 = [0], arr2 = [1]
Output: [1]

```

**Constraints:**

- `1 <= arr1.length, arr2.length <= 1000`
- `arr1[i]` and `arr2[i]` are `0` or `1`
- `arr1` and `arr2` have no leading zeros

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2) {
        if (arr2.size() > arr1.size()) {
            swap(arr1, arr2);
        }
        // 保证 arr1.size() >= arr2.size()；
        int n = arr1.size();
        vector<int> new_arr2(n);
        for (int i = n - arr2.size(); i < n; ++i) {
            new_arr2[i] = arr2[i - (n - arr2.size())];
        }
        swap(new_arr2, arr2);
        vector<int> res(arr1.size() + 2);
        int carry = 0;
        for (int i = n - 1; i >= 0; --i) {
            int tmp = arr1[i] + arr2[i] + carry;
            if (tmp >= 2) {
                res[i + 2] = tmp - 2;
                carry = -1;
            } else if (tmp == -1) {
                res[i + 2] = 1;
                carry = 1;
            } else {
                res[i + 2] = tmp;
                carry = 0;
            }
        }
        if (carry == -1) {
            res[1] = 1;
            res[0] = 1;
            return res;
        }
        res[1] = carry;
        vector<int> ans;
        int idx = 0;
        for (int i = 0; i < n + 2; ++i) {
            if (res[i] != 0) {
                return {res.begin() + i, res.end()};
            }
        }
        return {0};
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> arr1;
    LeetCodeIO::scan(cin, arr1);
    vector<int> arr2;
    LeetCodeIO::scan(cin, arr2);

    Solution *obj = new Solution();

    auto res = obj->addNegabinary(arr1, arr2);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
