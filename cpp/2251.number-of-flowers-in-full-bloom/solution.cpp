// Created by zwyyy456 at 2023/09/28 09:58
// leetgo: 1.3.8
// https://leetcode.com/problems/number-of-flowers-in-full-bloom/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int solve(vector<vector<int>> &start, int cur, vector<vector<int>> &end) {
        int l = 0, r = start.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (start[mid][0] <= cur) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int cnt1 = start.size() - l;
        l = 0, r = end.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (end[mid][1] < cur) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int cnt2 = l;
        return start.size() - cnt1 - cnt2;
    }
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people) {
        vector<vector<int>> start(flowers.begin(), flowers.end());
        sort(start.begin(), start.end());
        auto cmp = [](vector<int> &v1, vector<int> &v2) {
            return v1[1] <= v2[1];
        };
        sort(flowers.begin(), flowers.end(), cmp); // 按照花的枯萎时间从小到大排序
        vector<int> ans(people.size());
        int n = people.size();
        for (int i = 0; i < n; ++i) {
            ans[i] = solve(start, people[i], flowers);
        }
        return ans;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> flowers;
    LeetCodeIO::scan(cin, flowers);
    vector<int> people;
    LeetCodeIO::scan(cin, people);

    Solution *obj = new Solution();
    auto res = obj->fullBloomFlowers(flowers, people);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
