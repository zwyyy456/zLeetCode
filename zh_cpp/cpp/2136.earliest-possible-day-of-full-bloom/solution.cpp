// Created by zwyyy456 at 2023/10/05 18:27
// leetgo: 1.3.8
// https://leetcode.cn/problems/earliest-possible-day-of-full-bloom/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> plantTime;
	LeetCodeIO::scan(cin, plantTime);
	vector<int> growTime;
	LeetCodeIO::scan(cin, growTime);

	Solution *obj = new Solution();
	auto res = obj->earliestFullBloom(plantTime, growTime);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
