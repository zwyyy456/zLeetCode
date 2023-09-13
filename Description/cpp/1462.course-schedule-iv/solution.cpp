// Created by zwyyy456 at 2023/09/12 20:13
// leetgo: 1.3.8
// https://leetcode.cn/problems/course-schedule-iv/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int numCourses;
	LeetCodeIO::scan(cin, numCourses);
	vector<vector<int>> prerequisites;
	LeetCodeIO::scan(cin, prerequisites);
	vector<vector<int>> queries;
	LeetCodeIO::scan(cin, queries);

	Solution *obj = new Solution();
	auto res = obj->checkIfPrerequisite(numCourses, prerequisites, queries);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
