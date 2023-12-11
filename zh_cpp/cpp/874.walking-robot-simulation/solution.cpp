// Created by zwyyy456 at 2023/07/20 14:30
// leetgo: 1.3.1
// https://leetcode.cn/problems/walking-robot-simulation/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> commands; LeetCodeIO::scan(cin, commands);
	vector<vector<int>> obstacles; LeetCodeIO::scan(cin, obstacles);

	Solution *obj = new Solution();

	auto res = obj->robotSim(commands, obstacles);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
