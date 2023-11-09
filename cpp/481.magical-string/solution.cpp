// Created by zwyyy456 at 2023/10/27 14:39
// leetgo: 1.3.8
// https://leetcode.com/problems/magical-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
class Solution {
public:
    vector<int> s;
    int flag = 0;
    int magicalString(int n) {
        if (flag == 0) {
            s.resize(1e6 + 1);
            int R = 1e5;
            flag = 1;
            s[0] = 1;
            int l = 0, r = 1;
            while (r <= R) {
                if (s[l] == 1) {
                    if (s[r - 1] == 1) {
                        s[r++] = 2;
                    } else {

                            s[r++] = 1;
                    }
                } else { // s[l] == 2
                    if (s[l - 1] == 1) {
                        if (s[r - 1] == 1) {
                            s[r++] = 2;
                            s[r++] = 2;
                        } else {
                            s[r++] = 1;
                            s[r++] = 1;
                        }
                    } else {
                        if (s[r - 1] == 1) {
                            s[r++] = 2;
                            s[r++] = 2;
                        } else {
                            s[r++] = 1;
                            s[r++] = 1;
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 1) {
                res++;
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n;
	LeetCodeIO::scan(cin, n);

	Solution *obj = new Solution();
	auto res = obj->magicalString(n);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
