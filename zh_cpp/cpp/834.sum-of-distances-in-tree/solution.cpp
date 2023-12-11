// Created by zwyyy456 at 2023/07/18 10:16
// leetgo: 1.3.1
// https://leetcode.cn/problems/sum-of-distances-in-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n; LeetCodeIO::scan(cin, n);
	vector<vector<int>> edges; LeetCodeIO::scan(cin, edges);

	Solution *obj = new Solution();

	auto res = obj->sumOfDistancesInTree(n, edges);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
