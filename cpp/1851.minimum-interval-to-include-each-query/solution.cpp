// Created by zwyyy456 at 2023/07/18 10:34
// leetgo: 1.3.1
// https://leetcode.com/problems/minimum-interval-to-include-each-query/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
       	 
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> intervals; LeetCodeIO::scan(cin, intervals);
	vector<int> queries; LeetCodeIO::scan(cin, queries);

	Solution *obj = new Solution();

	auto res = obj->minInterval(intervals, queries);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
