// Created by zwyyy456 at 2023/10/06 11:52
// leetgo: 1.3.8
// https://leetcode.com/problems/number-of-flowers-in-full-bloom/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int upper(vector<int> &arr, int time) {
        int l = 0, r = arr.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] <= time) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    int lower(vector<int> &arr, int time) {
        int l = 0, r = arr.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] < time) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people) {
        // 二分
        int n = flowers.size();
        vector<int> start(n), end(n);
        for (int i = 0; i < n; ++i) {
            start[i] = flowers[i][0];
            end[i] = flowers[i][1];
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int> ans;
        for (int time : people) {
            int res = upper(start, time) - lower(end, time);
            ans.push_back(res);
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
