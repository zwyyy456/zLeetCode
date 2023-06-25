// Created by zwyyy456 at 2023/06/15 10:46
// leetgo: 1.3.1
// https://leetcode.com/problems/longest-uncommon-subsequence-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> strs; LeetCodeIO::scan(cin, strs);

	Solution *obj = new Solution();

	auto res = obj->findLUSlength(strs);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
