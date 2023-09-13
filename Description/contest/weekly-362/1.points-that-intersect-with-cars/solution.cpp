// Created by zwyyy456 at 2023/09/10 11:13
// leetgo: 1.3.8
// https://leetcode.cn/problems/points-that-intersect-with-cars/
// https://leetcode.cn/contest/weekly-contest-362/problems/points-that-intersect-with-cars/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->numberOfPoints(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
