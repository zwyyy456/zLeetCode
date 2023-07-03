// Created by zwyyy456 at 2023/06/15 10:40
// leetgo: 1.3.1
// https://leetcode.com/problems/continuous-subarray-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums; LeetCodeIO::scan(cin, nums);
	int k; LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();

	auto res = obj->checkSubarraySum(nums, k);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
