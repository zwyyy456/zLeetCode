/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
#include <string>
#include <unordered_set>
using std::string;
using std::unordered_set;
class Solution {
  public:
    string reverseVowels(string s) {
        unordered_set<char> mset{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            if (mset.find(s[l]) != mset.end() && mset.find(s[r]) != mset.end()) {
                char tmp = s[l];
                s[l++] = s[r];
                s[r--] = tmp;
            } else if (mset.find(s[l]) != mset.end() && mset.find(s[r]) == mset.end())
                r--;
            else if (mset.find(s[l]) == mset.end() && mset.find(s[r]) != mset.end())
                l++;
            else {
                r--;
                l++;
            }
        }
        return s;
    }
};
// @lc code=end
