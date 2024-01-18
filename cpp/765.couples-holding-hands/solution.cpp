// Created by zwyyy456 at 2023/11/11 13:13
// leetgo: 1.3.8
// https://leetcode.com/problems/couples-holding-hands/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> row;
	LeetCodeIO::scan(cin, row);

	Solution *obj = new Solution();
	auto res = obj->minSwapsCouples(row);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
