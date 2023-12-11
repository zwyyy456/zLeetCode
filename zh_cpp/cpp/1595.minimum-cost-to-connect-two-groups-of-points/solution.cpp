// Created by zwyyy456 at 2023/06/21 11:42
// leetgo: 1.3.1
// https://leetcode.cn/problems/minimum-cost-to-connect-two-groups-of-points/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> cost; LeetCodeIO::scan(cin, cost);

	Solution *obj = new Solution();

	auto res = obj->connectTwoGroups(cost);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
