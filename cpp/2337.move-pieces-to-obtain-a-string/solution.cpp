// Created by zwyyy456 at 2023/08/21 09:44
// leetgo: 1.3.5
// https://leetcode.com/problems/move-pieces-to-obtain-a-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool canChange(string start, string target) {
        int n = start.size();
        for (int i = 0; i < n; ++i) {
            if (start[i] == target[i]) {
                continue;
            }
            if (start[i] == 'L' || target[i] == 'R') {
                return false;
            }
            if (target[i] == 'L') {
                if (start[i] == 'R') {
                    return false;
                }
                stack<int> stk;
                while (i < n && start[i] != 'R' && target[i] != 'R') {
                    if (target[i] == 'L') {
                        stk.push(1);
                    }
                    if (start[i] == 'L') {
                        if (!stk.empty() && stk.top() == 1) {
                            stk.pop();
                        } else {
                            return false;
                        }
                    }
                    ++i;
                }
                if (!stk.empty()) {
                    return false;
                }
                --i;
            } else if (start[i] == 'R') {
                if (target[i] == 'L') {
                    return false;
                }
                stack<int> stk;
                while (i < n && start[i] != 'L' && target[i] != 'L') {
                    if (start[i] == 'R') {
                        stk.push(0);
                    }
                    if (target[i] == 'R') {
                        if (!stk.empty() && stk.top() == 0) {
                            stk.pop();
                        } else {
                            return false;
                        }
                    }
                    ++i;
                }
                if (!stk.empty()) {
                    return false;
                }
                --i;
            }
        }
        return true;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string start;
    LeetCodeIO::scan(cin, start);
    string target;
    LeetCodeIO::scan(cin, target);

    Solution *obj = new Solution();
    auto res = obj->canChange(start, target);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
