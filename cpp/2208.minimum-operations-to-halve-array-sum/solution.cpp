// Created by zwyyy456 at 2023/07/25 08:46
// leetgo: 1.3.1
// https://leetcode.com/problems/minimum-operations-to-halve-array-sum/

#include <bits/stdc++.h>
#include <numeric>
#include <queue>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
class Solution {
  public:
    int halveArray(vector<int> &nums) {
        double total = accumulate(nums.begin(), nums.end(), 0);
        priority_queue<double> pq;
        for (int num : nums) {
            pq.push(num);
        }
        double sum = total;
        int res = 0;
        while (2 * sum > total) {
            double half = pq.top() / 2;
            sum -= half;
            pq.pop();
            pq.push(half);
            ++res;
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();

    auto res = obj->halveArray(nums);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
