// Created by zwyyy456 at 2023/09/06 09:38
// leetgo: 1.3.8
// https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> pairs;
	LeetCodeIO::scan(cin, pairs);

	Solution *obj = new Solution();
	auto res = obj->checkWays(pairs);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
