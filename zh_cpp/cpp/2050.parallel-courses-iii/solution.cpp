// Created by zwyyy456 at 2023/07/28 16:00
// leetgo: 1.3.2
// https://leetcode.cn/problems/parallel-courses-iii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n; LeetCodeIO::scan(cin, n);
	vector<vector<int>> relations; LeetCodeIO::scan(cin, relations);
	vector<int> time; LeetCodeIO::scan(cin, time);

	Solution *obj = new Solution();

	auto res = obj->minimumTime(n, relations, time);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
