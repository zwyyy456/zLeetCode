// Created by zwyyy456 at 2023/10/27 13:37
// leetgo: 1.3.8
// https://leetcode.com/problems/minimum-number-of-refueling-stops/

#include <bits/stdc++.h>
#include <queue>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // 二分答案
        stations.emplace_back({target, 0});
        int n = stations.size();
        sort(stations.begin(), stations.end());
        auto cmp = [&stations](int i, int j) {
        	return stations[i][1] < stations[j][1];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int res = 0, cur = 0;
        for (int i = 0; i < n; ++i) {
        	startFuel -= (stations[i][0] - cur);
        	cur = stations[i][0];
        	if (startFuel < 0) {
        		while (!pq.empty() && startFuel < 0) {
        			startFuel += stations[pq.top()][1];
        			++res;
        		}
        		if (startFuel < 0) {
        			return -1;
        		}
        	}
        	pq.push(i);
        }
        return res;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int target;
	LeetCodeIO::scan(cin, target);
	int startFuel;
	LeetCodeIO::scan(cin, startFuel);
	vector<vector<int>> stations;
	LeetCodeIO::scan(cin, stations);

	Solution *obj = new Solution();
	auto res = obj->minRefuelStops(target, startFuel, stations);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
