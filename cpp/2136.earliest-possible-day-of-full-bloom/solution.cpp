// Created by zwyyy456 at 2023/10/05 18:19
// leetgo: 1.3.8
// https://leetcode.com/problems/earliest-possible-day-of-full-bloom/

#include <bits/stdc++.h>
#include <numeric>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime) {
        int time = accumulate(plantTime.begin(), plantTime.end(), 0);
        int cur = 0;
        int n = plantTime.size();
        vector<int> ids(n);
        for (int i = 0; i < n; ++i) {
            ids[i] = i;
        }
        auto cmp = [&growTime](int i, int j) {
            return growTime[i] > growTime[j];
        };
        sort(ids.begin(), ids.end(), cmp);
        for (int i = 0; i < n; ++i) {
            int idx = ids[i];
            cur += plantTime[idx];
            time = max(time, cur + growTime[idx]);
        }
        return time;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> plantTime;
    LeetCodeIO::scan(cin, plantTime);
    vector<int> growTime;
    LeetCodeIO::scan(cin, growTime);

    Solution *obj = new Solution();
    auto res = obj->earliestFullBloom(plantTime, growTime);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
