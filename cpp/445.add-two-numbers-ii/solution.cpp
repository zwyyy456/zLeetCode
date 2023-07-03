// Created by zwyyy456 at 2023/07/03 22:34
// leetgo: 1.3.2
// https://leetcode.com/problems/add-two-numbers-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* l1; LeetCodeIO::scan(cin, l1);
	ListNode* l2; LeetCodeIO::scan(cin, l2);

	Solution *obj = new Solution();

	auto res = obj->addTwoNumbers(l1, l2);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
