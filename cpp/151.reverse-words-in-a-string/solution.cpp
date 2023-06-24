/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
#include <string>
using std::string;
class Solution {
  public:
    void rmExtraSpace(string &s) {
        int i = 0;
        int low = 0;
        if (s[0] == ' ') {
            for (i = 1; i < s.size(); i++) {
                if (s[i] != ' ' || (s[i] == ' ' && s[i - 1] != ' '))
                    s[low++] = s[i];
            }
        } else {
            s[low++] = s[i];
            for (i = 1; i < s.size(); i++) {
                if (s[i] != ' ' || (s[i] == ' ' && s[i - 1] != ' '))
                    s[low++] = s[i];
            }
        }
        if (s[low - 1] == ' ')
            s.resize(low - 1);
        else
            s.resize(low);
    }
    void reverseString(string &s, int i, int j) {
        if (i < 0 || j > s.size() - 1)
            return;
        else {
            while (i <= j) {
                char temp = s[i];
                s[i++] = s[j];
                s[j--] = temp;
            }
        }
    }
    void rmSpace(string &s) {
        int low = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (low != 0)
                    s[low++] = ' ';
                while (s[i] != ' ') {
                    s[low++] = s[i++];
                }
            }
        }
        s.resize(low);
    }
    string reverseWords(string s) {
        rmExtraSpace(s);
        char temp;
        reverseString(s, 0, s.size() - 1);
        for (int i = 0; i < s.size(); i++) {
            int l = i;
            while (i < s.size() && s[i] != ' ')
                i++;
            reverseString(s, l, i - 1);
        }
        return s;
    }
};
// @lc code=end
