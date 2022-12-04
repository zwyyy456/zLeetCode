/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
#include <string>
using std::string;
class Solution {
  private:
    int max(int a, int b) {
        return a > b ? a : b;
    }

  public:
    int longestSubstring(string s, int k) {
        int arr[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            arr[s[i] - 'a']++;
        }
        int len = 0;
        int last_i = -1;
        int next_i = 0;
        for (int i = 0; i < s.size(); i++) {
            next_i = i;
            len = max(len, next_i - last_i);
            if (0 < arr[s[i] - 'a'] && arr[s[i] - 'a'] < k) {
                last_i = i;
            }
        }
        // len = max(len, s.size() - last_i);
        return len;
    }
};
// @lc code=end
