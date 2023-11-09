// Created by zwyyy456 at 2023/10/30 09:01
// leetgo: 1.3.8
// https://leetcode.com/problems/h-index-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int hIndex(vector<int> &citations) {
        // binary search
        int l = 0, r = citations.size();
        int n = citations.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (citations[mid] < n - mid) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return n - l;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> citations;
    LeetCodeIO::scan(cin, citations);

    Solution *obj = new Solution();
    auto res = obj->hIndex(citations);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
