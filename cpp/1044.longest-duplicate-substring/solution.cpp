// Created by zwyyy456 at 2023/10/20 11:42
// leetgo: 1.3.8
// https://leetcode.com/problems/longest-duplicate-substring/

#include <_types/_uint64_t.h>
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool check(int mid, string s, vector<uint64_t> &S, vector<uint64_t> &A, string &res) {
        unordered_map<uint64_t, int> cnt;
        for (int i = 0; i + mid <= s.size(); ++i) {
            // 求 S[i + 1, i + mid]
            uint64_t key = S[i + mid] - S[i] * A[mid];
            ++cnt[key];
            if (cnt[key] > 1) {
                res = s.substr(i, mid);
                return true;
            }
        }
        return false;
    }
    string longestDupSubstring(string s) {
        int n = s.size();
        vector<uint64_t> S(n + 1);
        S[0] = s[0];
        vector<uint64_t> A(n + 1);
        A[0] = 1;
        const uint64_t a = 1313131;
        string res = "";
        for (int i = 1; i <= n; ++i) {
            S[i] = S[i - 1] * a + s[i - 1];
            A[i] = a * A[i - 1];
        }
        int l = 0, r = s.size() + 1;
        unordered_map<uint64_t, int> cnt;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(mid, s, S, A, res)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);

    Solution *obj = new Solution();
    auto res = obj->longestDupSubstring(s);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
