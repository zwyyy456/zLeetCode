// Created by zwyyy456 at 2023/09/25 09:40
// leetgo: 1.3.8
// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);
	vector<vector<int>> queries;
	LeetCodeIO::scan(cin, queries);

	Solution *obj = new Solution();
	auto res = obj->maximizeXor(nums, queries);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
