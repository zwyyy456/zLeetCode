// Created by zwyyy456 at 2023/07/25 08:55
// leetgo: 1.3.1
// https://leetcode.com/problems/custom-sort-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    string customSortString(string order, string s) {
    	vector<int> ch_order(26);
    	for (int i = 0; i < order.size(); ++i) {
    		ch_order[order[i] - 'a'] = i;
    	}
    	vector<char> chs(s.begin(), s.end());
    	auto cmp = [&ch_order](char a, char b) {
    		return ch_order[a - 'a'] < ch_order[b - 'a'];
    	};
    	sort(chs.begin(), chs.end(), cmp);
    	string res(chs.begin(), chs.end());
    	return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string order;
    LeetCodeIO::scan(cin, order);
    string s;
    LeetCodeIO::scan(cin, s);

    Solution *obj = new Solution();

    auto res = obj->customSortString(order, s);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
