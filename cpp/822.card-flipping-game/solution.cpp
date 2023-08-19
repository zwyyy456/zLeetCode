// Created by zwyyy456 at 2023/08/02 13:41
// leetgo: 1.3.1
// https://leetcode.com/problems/card-flipping-game/

#include <bits/stdc++.h>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int flipgame(vector<int> &fronts, vector<int> &backs) {
        unordered_set<int> back_num(backs.begin(), backs.end());
        int n = backs.size();
        for (int i = 0; i < n; ++i) {
            back_num.insert(fronts[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i] && back_num.find(backs[i]) != back_num.end()) {
                back_num.erase(backs[i]);
            }
        }
        int res = 1001;
        if (back_num.empty()) {
            return 0;
        }
        for (int num : back_num) {
            res = min(num, res);
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> fronts;
    LeetCodeIO::scan(cin, fronts);
    vector<int> backs;
    LeetCodeIO::scan(cin, backs);

    Solution *obj = new Solution();

    auto res = obj->flipgame(fronts, backs);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
