/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
#include <string>
using std::string;
class Solution {
  public:
    void swap(char &c1, char &c2) {
        char temp = c1;
        c1 = c2;
        c2 = temp;
    }
    int min(int a, int b) {
        return a < b ? a : b;
    }
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            int end = s.size() - 1;
            for (int l = i, r = min(l + k - 1, end); l <= r; l++, r--) {
                swap(s[l], s[r]);
            }
        }
        return s;
    }
};
// @lc code=end
