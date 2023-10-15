// Created by zwyyy456 at 2023/10/06 20:25
// leetgo: 1.3.8
// https://leetcode.cn/problems/number-of-flowers-in-full-bloom/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> flowers;
	LeetCodeIO::scan(cin, flowers);
	vector<int> people;
	LeetCodeIO::scan(cin, people);

	Solution *obj = new Solution();
	auto res = obj->fullBloomFlowers(flowers, people);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
