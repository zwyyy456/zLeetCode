// Created by zwyyy456 at 2023/06/01 08:59
// https://leetcode.com/problems/maximum-tastiness-of-candy-basket/

/*
2517. Maximum Tastiness of Candy Basket (Medium)
You are given an array of positive integers `price` where `price[i]` denotes the price of the `ith`
candy and a positive integer `k`.

The store sells baskets of `k` **distinct** candies. The **tastiness** of a candy basket is the
smallest absolute difference of the **prices** of any two candies in the basket.

Return the **maximum** tastiness of a candy basket.

**Example 1:**

```
Input: price = [13,5,1,8,21,2], k = 3
Output: 8
Explanation: Choose the candies with the prices [13,5,21].
The tastiness of the candy basket is: min(|13 - 5|, |13 - 21|, |5 - 21|) = min(8, 8, 16) = 8.
It can be proven that 8 is the maximum tastiness that can be achieved.

```

**Example 2:**

```
Input: price = [1,3,1], k = 2
Output: 2
Explanation: Choose the candies with the prices [1,3].
The tastiness of the candy basket is: min(|1 - 3|) = min(2) = 2.
It can be proven that 2 is the maximum tastiness that can be achieved.

```

**Example 3:**

```
Input: price = [7,7,7,7], k = 2
Output: 0
Explanation: Choosing any two distinct candies from the candies we have will result in a tastiness
of 0.

```

**Constraints:**

- `2 <= k <= price.length <= 10⁵`
- `1 <= price[i] <= 10⁹`

*/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int Bsearch(int target, vector<int> &price, int left) {
        int right = price.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (price[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    bool Check(int mid, vector<int> &price, int k, int n) {
        int start = 0;
        for (int i = 0; i < k; ++i) {
            start = Bsearch(price[start] + mid, price, start);
            if (start >= n) {
                return false;
            }
        }
        return true;
    }
    int maximumTastiness(vector<int> &price, int k) {
        // 先排序，然后考虑是二分答案还是双指针
        sort(price.begin(), price.end());
        // 二分答案，时间复杂度为 log(price[i]) * k * log(n)
        int n = price.size();
        int left = 0, right = (price[n - 1] - price[0]) / k + 2; // 先看看 k 行不行，不行就改成 2
        while (left < right) {
            // 左闭右开
            int mid = left + (right - left) / 2;
            if (Check(mid, price, k, n)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> price;
    LeetCodeIO::scan(cin, price);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();

    auto res = obj->maximumTastiness(price, k);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
