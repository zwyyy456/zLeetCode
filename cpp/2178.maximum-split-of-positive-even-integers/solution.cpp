// Created by zwyyy456 at 2023/07/06 11:25
// leetgo: 1.3.1
// https://leetcode.com/problems/maximum-split-of-positive-even-integers/

#include <algorithm>
#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    using ll = long long;
    // 返回长度
    ll Bfind(int n, ll finalSum) {
        ll l = 1, r = n;
        while (l < r) {
            ll mid = l + (r - l) / 2;
            ll tmp = mid * (mid + 1) / 2;
            if (tmp < finalSum) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<ll> ans;
        if (finalSum % 2 == 1) {
            return ans;
        }
        ll n = 100001;
        ll idx = Bfind(n, finalSum / 2);
        if (idx * (idx + 1) == finalSum) {
        	for (ll i = 1; i <= idx; ++i) {
        		ans.push_back(2 * i);
        	}
        		return ans;
        }
        ll residue = finalSum - idx * (idx - 1);
        for (ll i = 1; i <= idx - 1; ++i) {
        	ans.push_back(2 * i);
        }
        ans[ans.size() - 1] += residue;
        return ans;

    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int64_t finalSum;
    LeetCodeIO::scan(cin, finalSum);

    Solution *obj = new Solution();

    auto res = obj->maximumEvenSplit(finalSum);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
