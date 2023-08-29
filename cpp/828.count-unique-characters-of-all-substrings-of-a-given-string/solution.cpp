// Created by zwyyy456 at 2023/07/26 20:05
// leetgo: 1.3.1
// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int uniqueLetterString(string s) {
        // 维护每个字符左侧相同字符的最大坐标
        int n = s.size();
        vector<int> arr(26, -1);
        vector<pair<int, int>> left_same(n, {-1, -1});
        for (int i = 0; i < n; ++i) {
            if (arr[s[i] - 'A'] != -1) {
                left_same[i].first = left_same[arr[s[i] - 'A']].second;
                left_same[i].second = arr[s[i] - 'A'];
            }
            arr[s[i] - 'A'] = i;
        }
        vector<int> dp(n);
        dp[0] = 1;
        int sum = 1;
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + i - left_same[i].second - (left_same[i].second - left_same[i].first);
            sum += dp[i];
        }
        return sum;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string s;
    LeetCodeIO::scan(cin, s);

    Solution *obj = new Solution();

    auto res = obj->uniqueLetterString(s);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
