// Created by zwyyy456 at 2023/07/06 14:33
// leetgo: 1.3.1
// https://leetcode.com/problems/basic-calculator-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int calculate(string s) {
        // stack
        stack<char> ops;
        stack<int> nums;
        for (int i = 0; i < s.size(); ++i) {
            int tmp = 0;
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] == '+' || s[i] == '-') {
                ops.push(s[i]);
            } else if (s[i] == '*' || s[i] == '/') {
                char c = s[i];
                int right = 0;
                ++i;
                while (i < s.size() && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/') {
                    if (s[i] == ' ') {
                        ++i;
                    } else {
                        right = right * 10 + s[i] - '0';
                        ++i;
                    }
                }
                int left = nums.top();
                nums.pop();
                if (c == '*') {
                    nums.push(left * right);
                } else {
                    nums.push(left / right);
                }
            } else {
                while (s[i] <= '9' && s[i] >= '0') {
                    tmp = tmp * 10 + s[i] - '0';
                    ++i;
                }
            }
            nums.push(tmp);
        }
        stack<char> op_new;
        stack<int> nums_new;
        while (!ops.empty()) {
            op_new.push(ops.top());
            ops.pop();
        }
        while (!nums_new.empty()) {
            nums_new.push(nums.top());
            nums.pop();
        }
        while (!op_new.empty()) {
            int left = nums_new.top();
            nums_new.pop();
            int right = nums_new.top();
            nums_new.pop();
            char op = op_new.top();
            op_new.pop();
            if (op == '+') {
                nums_new.push(left + right);
            } else {
                nums_new.push(left - right);
            }
        }
        return nums_new.top();
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);

    Solution *obj = new Solution();

    auto res = obj->calculate(s);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
