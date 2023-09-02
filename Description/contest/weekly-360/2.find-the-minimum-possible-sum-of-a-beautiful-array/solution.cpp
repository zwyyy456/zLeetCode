// Created by zwyyy456 at 2023/08/27 10:31
// leetgo: 1.3.1
// https://leetcode.cn/problems/find-the-minimum-possible-sum-of-a-beautiful-array/
// https://leetcode.cn/contest/weekly-contest-360/problems/find-the-minimum-possible-sum-of-a-beautiful-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n; LeetCodeIO::scan(cin, n);
	int target; LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();

	auto res = obj->minimumPossibleSum(n, target);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
