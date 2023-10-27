// Created by zwyyy456 at 2023/10/27 14:14
// leetgo: 1.3.8
// https://leetcode.com/problems/count-nodes-with-the-highest-score/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> parents;
	LeetCodeIO::scan(cin, parents);

	Solution *obj = new Solution();
	auto res = obj->countHighestScoreNodes(parents);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
