// Created by zwyyy456 at 2023/07/20 08:58
// leetgo: 1.3.1
// https://leetcode.cn/problems/reveal-cards-in-increasing-order/

#include <bits/stdc++.h>
#include <deque>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
    	sort(deck.begin(), deck.end());
    	// 用双端队列就可以了
    	int n = deck.size();
    	vector<int> res(n);
    	deque<int> dq;
    	for (int i = 0; i < n; ++i) {
    		dq.push_back(i);
    	}
    	int cnt = 0;
    	for (int card : deck) {
    		res[dq.front()] = card;
    		dq.pop_front();
    		if (!dq.empty()) {
    			dq.push_back(dq.front());
    			dq.pop_front();
    		}
    	}
    	return res;
    }

};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> deck; LeetCodeIO::scan(cin, deck);

	Solution *obj = new Solution();

	auto res = obj->deckRevealedIncreasing(deck);

	LeetCodeIO::print(out_stream, res);
	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
