// Created by zwyyy456 at 2023/08/27 10:31
// leetgo: 1.3.1
// https://leetcode.cn/problems/minimum-operations-to-form-subsequence-with-target-sum/
// https://leetcode.cn/contest/weekly-contest-360/problems/minimum-operations-to-form-subsequence-with-target-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums; LeetCodeIO::scan(cin, nums);
	int target; LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();

	auto res = obj->minOperations(nums, target);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
