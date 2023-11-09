// Created by zwyyy456 at 2023/11/08 22:51
// leetgo: 1.3.8
// https://leetcode.com/problems/max-chunks-to-make-sorted-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> arr;
	LeetCodeIO::scan(cin, arr);

	Solution *obj = new Solution();
	auto res = obj->maxChunksToSorted(arr);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
