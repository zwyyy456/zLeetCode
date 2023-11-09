// Created by zwyyy456 at 2023/10/15 16:14
// leetgo: 1.3.8
// https://leetcode.cn/problems/max-sum-of-rectangle-no-larger-than-k/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> matrix;
	LeetCodeIO::scan(cin, matrix);
	int k;
	LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();
	auto res = obj->maxSumSubmatrix(matrix, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
