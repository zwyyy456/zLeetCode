// Created by zwyyy456 at 2023/09/28 11:02
// leetgo: 1.3.8
// https://leetcode.com/problems/count-of-range-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);
	int lower;
	LeetCodeIO::scan(cin, lower);
	int upper;
	LeetCodeIO::scan(cin, upper);

	Solution *obj = new Solution();
	auto res = obj->countRangeSum(nums, lower, upper);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
