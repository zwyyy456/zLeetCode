// Created by zwyyy456 at 2023/08/09 18:49
// leetgo: 1.3.1
// https://leetcode.cn/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool digit(char c) {
        return c >= '0' && c <= '9';
    }
    bool isNumber(string s) {
        int n = s.size();
        int state = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == ' ') {
                continue;
            }
            if (state == 0) {
                if (digit(c)) {
                    state = 1;
                } else if (c == '.') {
                    state = 3;
                } else {
                    return false;
                }
            } else if (state == 1) {
                if (digit(c)) {
                    state = 2;
                } else if (c == '.') {
                    state = 3;
                } else if (c == 'e') {
                    state = 5;
                } else {
                    return false;
                }
            } else if (state == 2) { // 两位及以上整数
                if (digit(c)) {
                    continue;
                }
                if (c == '.') {
                    state = 3;
                } else {
                    return false;
                }
            } else if (state == 3) { // 小数点
                if (digit(c)) {
                    state = 6;
                } else {
                    return false;
                }
            } else if (state == 4) { // 正负号
                if (digit(c)) {
                    state = 1;
                } else if (c == '.') {
                    state = 3;
                } else {
                    return false;
                }
            } else if (state == 5) { // e
                if (digit(c)) {
                    state = 7; // 只能是整数
                } else if (c == '+' || c == '-') {
                    state = 7;
                } else {
                    return false;
                }
            } else if (state == 6) {
                if (digit(c)) {
                    continue;
                }
                if (c == 'e') {
                    state = 5;
                } else {
                    return false;
                }
            } else if (state == 7) {
                if (!digit(c)) {
                    return false;
                }
            }
        }
        return true;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);

    Solution *obj = new Solution();

    auto res = obj->isNumber(s);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
