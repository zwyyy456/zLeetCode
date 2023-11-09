// Created by zwyyy456 at 2023/11/06 17:24
// leetgo: 1.3.8
// https://leetcode.com/problems/advantage-shuffle/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
        int n = nums2.size();
        vector<int> ids(n);
        for (int i = 0; i < n; ++i) {
            ids[i] = i;
        }
        auto cmp = [&nums2](int i, int j) {
            return nums2[i] < nums2[j];
        };
        sort(ids.begin(), ids.end(), cmp);
        map<int, int> mp;
        for (int &num : nums1) {
            mp[num]++;
        }
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            int idx = ids[i];
            auto iter = mp.upper_bound(nums2[idx]);
            res[i] = iter->first;
            if (--iter->second == 0) {
                mp.erase(iter);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (res[i] == -1) {
                auto iter = mp.begin();
                res[i] = iter->first;
                if (--iter->second == 0) {
                    mp.erase(iter);
                }
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums1;
    LeetCodeIO::scan(cin, nums1);
    vector<int> nums2;
    LeetCodeIO::scan(cin, nums2);

    Solution *obj = new Solution();
    auto res = obj->advantageCount(nums1, nums2);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
