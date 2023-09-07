// Created by zwyyy456 at 2023/09/03 09:22
// leetgo: 1.3.1
// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
       	int n = dist.size(); 
       	priority_queue<int, vector<int>, greater<>> time;
       	for (int i = 0; i < n; ++i) {
       		time.push(dist[i] / speed[i]);
       	}
       	int cur = 0;
       	while (!time.empty() && cur <= time.top()) {
       		time.pop();
       		++cur;
       	}
       	return cur + 1;	
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> dist; LeetCodeIO::scan(cin, dist);
	vector<int> speed; LeetCodeIO::scan(cin, speed);

	Solution *obj = new Solution();

	auto res = obj->eliminateMaximum(dist, speed);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
