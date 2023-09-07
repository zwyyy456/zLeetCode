// Created by zwyyy456 at 2023/08/27 10:31
// leetgo: 1.3.1
// https://leetcode.cn/problems/maximize-value-of-function-in-a-ball-passing-game/
// https://leetcode.cn/contest/weekly-contest-360/problems/maximize-value-of-function-in-a-ball-passing-game/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> receiver; LeetCodeIO::scan(cin, receiver);
	int64_t k; LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();

	auto res = obj->getMaxFunctionValue(receiver, k);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
