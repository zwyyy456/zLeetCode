// Created by zwyyy456 at 2023/12/06 15:44
// leetgo: 1.3.8
// https://leetcode.com/problems/different-ways-to-add-parentheses/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	int dfs(string &expression, vector<char> &ops, vector<int> &res, int idx) {
			
	}
    vector<int> diffWaysToCompute(string expression) {
       	vector<char> ops;
       	for (int i = 0; i < expression.size(); ++i) {
       		if (expression[i] == '-' || expression[i] == '+' || expression[i] == '*') {
       			ops.push_back(expression[i]);
       		}
       	} 
       	vector<int> res;
       	dfs(expression, ops, res, 0);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string expression;
	LeetCodeIO::scan(cin, expression);

	Solution *obj = new Solution();
	auto res = obj->diffWaysToCompute(expression);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
