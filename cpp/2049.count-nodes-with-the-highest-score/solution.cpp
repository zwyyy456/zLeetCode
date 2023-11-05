// Created by zwyyy456 at 2023/10/27 14:14
// leetgo: 1.3.8
// https://leetcode.com/problems/count-nodes-with-the-highest-score/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	int get_cnt(vector<int> &cnt, vector<vector<int>> &tree, int cur) {
		int res = 1;
		for (auto &child : tree[cur]) {
			res += get_cnt(cnt, tree, child);
		}
		cnt[cur] = res;
		return res;
	}
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> tree(n);
        vector<int> cnt(n, 0);
        vector<int> vis(n);
        int root = -1;
        for (int i = 0; i < n; ++i) {
        	if (parents[i] != -1) {
        		tree[parents[i]].push_back(i);
        	} else {
        		root = i;
        	}
        }
        get_cnt(cnt, tree, root);
        int res = 0;
        for (int i = 0; i < n; ++i) {
        	int tmp = cnt[root] - cnt[i] > 0 ?  cnt[root] - cnt[i] : 1;
        	for (int j = 0; j < tree[i].size(); ++j) {
        		tmp *= cnt[tree[i][j]];
        	}
        	res = max(res, tmp);
        }
        return res;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> parents;
	LeetCodeIO::scan(cin, parents);

	Solution *obj = new Solution();
	auto res = obj->countHighestScoreNodes(parents);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
