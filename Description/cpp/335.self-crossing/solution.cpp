// Created by zwyyy456 at 2023/07/28 14:16
// leetgo: 1.3.2
// https://leetcode.cn/problems/self-crossing/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool isSelfCrossing(vector<int> &distance) {
        int n = distance.size();
        if (n <= 3) {
            return 0;
        }
        for (int i = 3; i < n; ++i) {
            cout << i << endl;
            if (i == 3) {
                if (distance[2] <= distance[0] && distance[3] >= distance[1]) {
                    return true;
                }
            } else if (i == 4) {
                if ((distance[i - 1] == distance[i - 3] && distance[i] + distance[i - 4] >= distance[i - 2]) || (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3])) {
                    return true;
                }
            } else {
                if ((distance[i - 1] <= distance[i - 3] && distance[i] >= distance[i - 2]) || (distance[i] + distance[i - 4] >= distance[i - 2] && distance[i - 1] + distance[i - 5] >= distance[i - 3] && distance[i - 3] > distance[i - 5] && distance[i - 2] > distance[i - 4] && distance[i - 1] <= distance[i - 3]) || (distance[i - 1] == distance[i - 3] && distance[i] + distance[i - 4] >= distance[i - 2])) {
                    return true;
                }
            }
        }
        return false;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> distance;
    LeetCodeIO::scan(cin, distance);

    Solution *obj = new Solution();

    auto res = obj->isSelfCrossing(distance);

    LeetCodeIO::print(out_stream, res);
    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
