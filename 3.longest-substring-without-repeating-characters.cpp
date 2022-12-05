/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <unordered_set>
using std::max;
using std::string;
using std::unordered_set;
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int arr[96] = {0};
        int res = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            arr[s[r] - ' ']++;
            if (arr[s[r] - ' '] > 1) {
                while (l < r && arr[s[r] - ' '] > 1)
                    arr[s[l++] - ' ']--;
            } else {
                res = max(r - l + 1, res);
            }
        }
        return res;
    }
};
// @lc code=end
