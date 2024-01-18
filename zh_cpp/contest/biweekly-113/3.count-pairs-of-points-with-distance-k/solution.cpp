// Created by zwyyy456 at 2023/09/16 22:30
// leetgo: 1.3.5
// https://leetcode.cn/problems/count-pairs-of-points-with-distance-k/
// https://leetcode.cn/contest/biweekly-contest-113/problems/count-pairs-of-points-with-distance-k/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> coordinates;
	LeetCodeIO::scan(cin, coordinates);
	int k;
	LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();
	auto res = obj->countPairs(coordinates, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
