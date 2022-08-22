/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    void reverseString(vector<char> &s) {
        int left = 0;
        int right = s.size() - 1;
        char temp;
        for (int l = 0, r = s.size() - 1; l <= r; l++, r--) {
            temp = s[l];
            s[l] = s[r];
            s[r] = temp;
        }
    }
};
// @lc code=end
