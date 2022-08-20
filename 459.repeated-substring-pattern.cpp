/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
#include <string>
using std::string;
class Solution {
  public:
    void getNext(int *next, const string &s) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {
            // next[j + 1]指向匹配好的前缀的下一个字符
            // i指向后缀末尾位置
            while (j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        // string s2 = s + s;
        int next[s.size()];
        int len = s.size();
        int count = 0;
        getNext(next, s);
        if (next[len - 1] != -1 && len % (len - next[len - 1] - 1) == 0)
            return true;
        else
            return false;
    }
};
// @lc code=end
