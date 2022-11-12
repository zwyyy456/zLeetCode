/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> queue;
        for (int i = 0; i < people.size(); i++) {
            int tmp = people[i][1];
            queue.insert(tmp + queue.begin(), people[i]);
        }
        return queue;
    }
};
// @lc code=end
