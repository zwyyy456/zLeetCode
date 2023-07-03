// Created by zwyyy456 at 2023/06/25 09:50
// leetgo: 1.3.1
// https://leetcode.cn/problems/russian-doll-envelopes/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> envelopes; LeetCodeIO::scan(cin, envelopes);

	Solution *obj = new Solution();

	auto res = obj->maxEnvelopes(envelopes);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
