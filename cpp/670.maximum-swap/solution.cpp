// Created by zwyyy456 at 2023/07/13 22:58
// leetgo: 1.3.2
// https://leetcode.com/problems/maximum-swap/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int maximumSwap(int num) {
        vector<int> vec;
        while (num != 0) {
            vec.push_back(num % 10);
            num /= 10;
        }
        reverse(vec.begin(), vec.end());
        int res = 0;
        int n = vec.size();
        vector<int> r2l_max(n);
        int tmp = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (vec[i] > tmp) {
                r2l_max[i] = i;
                tmp = vec[i];
            } else {
                r2l_max[i] = r2l_max[i + 1];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (vec[i] < vec[r2l_max[i]]) {
                swap(vec[i], vec[r2l_max[i]]);
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            res = 10 * res + vec[i];
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int num;
    LeetCodeIO::scan(cin, num);

    Solution *obj = new Solution();

    auto res = obj->maximumSwap(num);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
