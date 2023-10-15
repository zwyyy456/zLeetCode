// Created by zwyyy456 at 2023/10/13 09:21
// leetgo: 1.3.8
// https://leetcode.com/problems/avoid-flood-in-the-city/

#include <bits/stdc++.h>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> avoidFlood(vector<int> &rains) {
        unordered_map<int, int> lakes;
        int cnt = 0;
        int n = rains.size();
        vector<int> ans(n, 1);
        set<int> canadd;
        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                ans[i] = -1;
                if (lakes.find(rains[i]) == lakes.end()) {
                    lakes[rains[i]] = i;
                } else {
                    if (canadd.empty()) {
                        return {};
                    }
                    auto it = canadd.lower_bound(lakes[rains[i]]);
                    if (it == canadd.end()) {
                        return {};
                    }
                    ans[*it] = rains[i];
                    canadd.erase(it);
                    lakes[rains[i]] = i;
                }
            } else {
                canadd.insert(i);
            }
        }
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> rains;
    LeetCodeIO::scan(cin, rains);

    Solution *obj = new Solution();
    auto res = obj->avoidFlood(rains);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
