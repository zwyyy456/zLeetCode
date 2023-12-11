// Created by zwyyy456 at 2023/07/02 10:31
// leetgo: 1.3.1
// https://leetcode.cn/problems/prime-pairs-with-target-sum/
// https://leetcode.cn/contest/weekly-contest-352/problems/prime-pairs-with-target-sum/

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> res;
        if (n < 4) {
            return res;
        }
        unordered_map<int, int> prime;
        vector<int> nums(n + 1);
        nums[0] = -1;
        nums[1] = -1; // -1 表示不是质数
        for (int i = 2; i <= n; ++i) {
            while (i <= n && nums[i] == -1) {
                ++i;
            }
            if (i <= n && nums[i] == 0) {
                prime[i] = 1;
                for (int j = i; j <= n; ++j) {
                    if (j % i == 0) {
                        nums[j] = -1;
                    }
                }
            }
        }
        for (auto &[key, val] : prime) {
            if (val != 1) {
                continue;
            }
            if (prime.find(n - key) != prime.end()) {
                res.push_back({key, n - key});
                prime[key] = 0;
                prime[n - key] = 0;
                ;
            } else {
                prime[key] = 0;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int n;
    LeetCodeIO::scan(cin, n);

    Solution *obj = new Solution();

    auto res = obj->findPrimePairs(n);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
