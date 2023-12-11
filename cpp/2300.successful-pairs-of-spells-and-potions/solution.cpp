// Created by zwyyy456 at 2023/11/10 22:10
// leetgo: 1.3.8
// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int bfind(vector<int> &potions, long long target) {
        int l = 0, r = potions.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (potions[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return potions.size() - l;
    }
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = bfind(potions, (success - 1) / spells[i]);
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> spells;
    LeetCodeIO::scan(cin, spells);
    vector<int> potions;
    LeetCodeIO::scan(cin, potions);
    int64_t success;
    LeetCodeIO::scan(cin, success);

    Solution *obj = new Solution();
    auto res = obj->successfulPairs(spells, potions, success);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
