// Created by zwyyy456 at 2023/09/16 22:30
// leetgo: 1.3.5
// https://leetcode.cn/problems/minimum-edge-reversals-so-every-node-is-reachable/
// https://leetcode.cn/contest/biweekly-contest-113/problems/minimum-edge-reversals-so-every-node-is-reachable/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n;
	LeetCodeIO::scan(cin, n);
	vector<vector<int>> edges;
	LeetCodeIO::scan(cin, edges);

	Solution *obj = new Solution();
	auto res = obj->minEdgeReversals(n, edges);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
