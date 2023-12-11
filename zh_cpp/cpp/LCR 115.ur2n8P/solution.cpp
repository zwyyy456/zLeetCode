// Created by zwyyy456 at 2023/08/15 15:28
// leetgo: 1.3.5
// https://leetcode.cn/problems/ur2n8P/

#include <bits/stdc++.h>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool sequenceReconstruction(vector<int> &nums, vector<vector<int>> &sequences) {
        // 即说明拓扑序唯一，并且所有的整数都处于拓扑排序中
        int n = nums.size();
        vector<unordered_set<int>> in(n + 1);
        vector<int> degree(n + 1);
        for (auto &vec : sequences) {
            for (int i = 1; i < vec.size(); ++i) {
                if (in[vec[i - 1]].find(vec[i]) == in[vec[i - 1]].end()) {
                    ++degree[vec[i]];
                }
                in[vec[i - 1]].insert(vec[i]);
            }
        }
        queue<int> q;
        vector<int> res;
        for (int i = 1; i <= n; ++i) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }
        while (q.size() == 1) {
            auto idx = q.front();
            res.push_back(idx);
            q.pop();
            for (int tail : in[idx]) {
                if (--degree[tail] == 0) {
                    q.push(tail);
                }
            }
        }
        return res.size() == n;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);
    vector<vector<int>> sequences;
    LeetCodeIO::scan(cin, sequences);

    Solution *obj = new Solution();
    auto res = obj->sequenceReconstruction(nums, sequences);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
