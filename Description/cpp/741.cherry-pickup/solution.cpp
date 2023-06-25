// Created by zwyyy456 at 2023/06/21 17:28
// leetgo: 1.3.1
// https://leetcode.cn/problems/cherry-pickup/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> grid; LeetCodeIO::scan(cin, grid);

	Solution *obj = new Solution();

	auto res = obj->cherryPickup(grid);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
