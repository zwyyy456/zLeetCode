// Created by zwyyy456 at 2023/10/27 14:02
// leetgo: 1.3.8
// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int h;
	LeetCodeIO::scan(cin, h);
	int w;
	LeetCodeIO::scan(cin, w);
	vector<int> horizontalCuts;
	LeetCodeIO::scan(cin, horizontalCuts);
	vector<int> verticalCuts;
	LeetCodeIO::scan(cin, verticalCuts);

	Solution *obj = new Solution();
	auto res = obj->maxArea(h, w, horizontalCuts, verticalCuts);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
