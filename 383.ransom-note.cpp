/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
#include <string>
using std::string;
class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26] = {0};
        for (char c : magazine)
            a[c - 'a']++;
        for (char c : ransomNote) {
            if (--a[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
