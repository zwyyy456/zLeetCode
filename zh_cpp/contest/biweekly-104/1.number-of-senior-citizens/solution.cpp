// Created by Bob at 2023/05/13 22:41
// https://leetcode.cn/problems/number-of-senior-citizens/
// https://leetcode.cn/contest/biweekly-contest-104/problems/number-of-senior-citizens/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int countSeniors(vector<string>& details) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> details; LeetCodeIO::scan(cin, details);

	Solution *obj = new Solution();

	auto res = obj->countSeniors(details);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
