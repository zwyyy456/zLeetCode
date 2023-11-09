// Created by zwyyy456 at 2023/10/12 09:23
// leetgo: 1.3.8
// https://leetcode.com/problems/nth-magical-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int factor(int a, int b) {
        while (b % a != 0) {
            int tmp = a;
            a = b % a;
            b = tmp;
        }
        return a;
    }
    int nthMagicalNumber(int n, int a, int b) {
        const int mod = 1e9 + 7;
        // 我们可以假设 a，b 互质，并且 a < b；a == b 的情况直接搞定
        // 非互质，则同时除以二者的最大公因数
        if (a == b) {
            return (((long)n % mod) * (a % mod)) % mod;
        }
        if (a > b) {
            swap(a, b);
        }
        const int fac = factor(a, b);
        a = a / fac;
        b = b / fac;
        long x = n / (a + b - 1);
        long y = n % (a + b - 1);
        vector<int> nums(a + b - 1);
        for (int i = 1; i <= b; ++i) {
            nums.push_back(i * a);
        }
        for (int i = 1; i < a; ++i) {
            nums.push_back(i * b);
        }
        sort(nums.begin(), nums.end());
        int res = (long)fac * ((x * a * b + nums[y]) % mod) % mod;
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);
    int a;
    LeetCodeIO::scan(cin, a);
    int b;
    LeetCodeIO::scan(cin, b);

    Solution *obj = new Solution();
    auto res = obj->nthMagicalNumber(n, a, b);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
