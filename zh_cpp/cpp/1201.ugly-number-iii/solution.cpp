// Created by zwyyy456 at 2023/10/17 11:11
// leetgo: 1.3.8
// https://leetcode.cn/problems/ugly-number-iii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {

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
	int c;
	LeetCodeIO::scan(cin, c);

	Solution *obj = new Solution();
	auto res = obj->nthUglyNumber(n, a, b, c);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
