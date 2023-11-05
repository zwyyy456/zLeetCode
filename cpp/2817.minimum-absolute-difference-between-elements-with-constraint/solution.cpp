// Created by zwyyy456 at 2023/10/19 10:22
// leetgo: 1.3.8
// https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
       	 
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);
	int x;
	LeetCodeIO::scan(cin, x);

	Solution *obj = new Solution();
	auto res = obj->minAbsoluteDifference(nums, x);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
