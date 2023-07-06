// Created by zwyyy456 at 2023/07/02 10:31
// leetgo: 1.3.1
// https://leetcode.cn/problems/sum-of-imbalance-numbers-of-all-subarrays/
// https://leetcode.cn/contest/weekly-contest-352/problems/sum-of-imbalance-numbers-of-all-subarrays/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums; LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();

	auto res = obj->sumImbalanceNumbers(nums);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
