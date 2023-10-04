// Created by zwyyy456 at 2023/10/04 12:17
// leetgo: 1.3.8
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int k;
	LeetCodeIO::scan(cin, k);
	vector<int> prices;
	LeetCodeIO::scan(cin, prices);

	Solution *obj = new Solution();
	auto res = obj->maxProfit(k, prices);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
