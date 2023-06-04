// Created by Bob at 2023/05/13 22:41
// https://leetcode.cn/problems/maximum-or/
// https://leetcode.cn/contest/biweekly-contest-104/problems/maximum-or/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums; LeetCodeIO::scan(cin, nums);
	int k; LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();

	auto res = obj->maximumOr(nums, k);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
