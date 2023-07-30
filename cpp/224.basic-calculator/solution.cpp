// Created by zwyyy456 at 2023/07/22 18:07
// leetgo: 1.3.2
// https://leetcode.com/problems/basic-calculator/

#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int cal(const string &s) {
        int sum = 0;
        int n = s.size();
        int i = 0;
        while (i < n) {
            char c = s[i];
            if (c == '+') {
                while (i < n && (s[i] > '9' || s[i] < '0')) {
                    ++i;
                }
                int tmp = 0;
                while (i < n && s[i] <= '9' && s[i] >= '0') {
                    tmp = 10 * tmp + s[i] - '0';
                    ++i;
                }
                sum += tmp;
            } else if (c == '-') {
                while (i < n && (s[i] > '9' || s[i] < '0')) {
                    ++i;
                }
                int tmp = 0;
                while (i < n && s[i] <= '9' && s[i] >= '0') {
                    tmp = 10 * tmp + s[i] - '0';
                    ++i;
                }
                sum -= tmp;
            } else if (c <= '9' && c >= '0') {
                int tmp = 0;
                while (i < n && s[i] <= '9' && s[i] >= '0') {
                    tmp = 10 * tmp + s[i] - '0';
                    ++i;
                }
                sum += tmp;
            } else {
                ++i;
            }
        }
        return sum;
    }
    int calculate(string s) {
        stack<int> nums;
        stack<char> parentheses;
        stack<string> to_cals;
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '(') {
                to_cals.push("(");
            } else if (c == ')') {
                vector<string> to_recover;
                while (!to_cals.empty() && to_cals.top() != "(") {
                    to_recover.push_back(to_cals.top());
                    to_cals.pop();
                }
                to_cals.pop();
                reverse(to_recover.begin(), to_recover.end());
                string to_cal = accumulate(to_recover.begin(), to_recover.end(), "");
                string tmp_res = to_string(cal(to_cal));
                to_cals.push(tmp_res);
            } else {
                string tmp;
                while (i < n && s[i] != '(' && s[i] != ')') {
                    tmp.push_back(s[i]);
                }
                to_cals.push(tmp);
                --i;
            }
        }
        vector<string> to_recover;
        while (!to_cals.empty() && to_cals.top() != "(") {
            to_recover.push_back(to_cals.top());
            to_cals.pop();
        }
        reverse(to_recover.begin(), to_recover.end());
        string to_cal = accumulate(to_recover.begin(), to_recover.end(), "");

        sum += cal(to_cal);
        return sum;
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
