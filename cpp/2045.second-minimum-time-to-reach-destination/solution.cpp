// Created by zwyyy456 at 2023/08/30 10:22
// leetgo: 1.3.5
// https://leetcode.com/problems/second-minimum-time-to-reach-destination/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n;
	LeetCodeIO::scan(cin, n);
	vector<vector<int>> edges;
	LeetCodeIO::scan(cin, edges);
	int time;
	LeetCodeIO::scan(cin, time);
	int change;
	LeetCodeIO::scan(cin, change);

	Solution *obj = new Solution();
	auto res = obj->secondMinimum(n, edges, time, change);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
