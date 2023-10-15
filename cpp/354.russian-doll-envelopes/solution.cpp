// Created by zwyyy456 at 2023/10/11 10:03
// leetgo: 1.3.8
// https://leetcode.com/problems/russian-doll-envelopes/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int bfind(vector<int> &vec, int target) {
        int l = 0, r = vec.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (vec[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        auto cmp = [](vector<int> &v1, vector<int> &v2) {
            if (v1[0] == v2[0]) {
                return v1[1] > v2[1];
            }
            return v1[0] < v2[0];
        };
        sort(envelopes.begin(), envelopes.end(), cmp);
        // 对 envelopes[1] 进行 lcs
        vector<int> vec;
        vec.push_back(envelopes[0][1]);
        int len = 1;
        for (auto &v : envelopes) {
            if (v[1] > vec.back()) {
                ++len;
                vec.push_back(v[1]);
            } else {
                int idx = bfind(vec, v[1]);
                vec[idx] = v[1];
            }
        }
        return len;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> envelopes;
    LeetCodeIO::scan(cin, envelopes);

    Solution *obj = new Solution();
    auto res = obj->maxEnvelopes(envelopes);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
