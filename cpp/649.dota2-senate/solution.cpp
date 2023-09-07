// Created by zwyyy456 at 2023/08/26 11:01
// leetgo: 1.3.1
// https://leetcode.com/problems/dota2-senate/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    string predictPartyVictory(string senate) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string senate; LeetCodeIO::scan(cin, senate);

	Solution *obj = new Solution();

	auto res = obj->predictPartyVictory(senate);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
