/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int sz = (g.size() <= s.size() ? g.size() : s.size());
        int i = 0;
        int j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] > s[j])
                j++;
            else {
                i++;
                j++;
            }
        }
        return i;
    }
};
// @lc code=end
