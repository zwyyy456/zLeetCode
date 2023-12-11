// Created by zwyyy456 at 2023/12/11 15:45
// leetgo: 1.3.8
// https://leetcode.com/problems/path-with-minimum-effort/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> heights;
	LeetCodeIO::scan(cin, heights);

	Solution *obj = new Solution();
	auto res = obj->minimumEffortPath(heights);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
