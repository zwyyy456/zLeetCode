// Created by zwyyy456 at 2023/10/13 11:28
// leetgo: 1.3.8
// https://leetcode.cn/problems/number-of-submatrices-that-sum-to-target/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> matrix;
	LeetCodeIO::scan(cin, matrix);
	int target;
	LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();
	auto res = obj->numSubmatrixSumTarget(matrix, target);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
