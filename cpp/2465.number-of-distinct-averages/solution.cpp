// Created by zwyyy456 at 2023/06/04 17:27
// https://leetcode.com/problems/number-of-distinct-averages/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums; LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();

	auto res = obj->distinctAverages(nums);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
