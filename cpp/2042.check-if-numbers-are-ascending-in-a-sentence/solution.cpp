/*
 * @lc app=leetcode id=2042 lang=cpp
 *
 * [2042] Check if Numbers Are Ascending in a Sentence
 */

// @lc code=start
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
  public:
    int mpow(int e, int x) {
        while (x--)
            e *= 10;
        return e;
    }
    int str2num(int l, int r, string &s) {
        int ans = 0;
        for (int i = l + 1; i < r; i++) {
            if (s[i] - '0' <= 9 && s[i] - '0' >= 0) {
                ans += mpow(s[i] - '0', r - i - 1);
            } else {
                return 0;
            }
        }
        return ans;
    }
    bool areNumbersAscending(string s) {
        int blank_l = 0;
        int blank_r = 0, tmp = 0;
        vector<int> numbers;
        s = " " + s + " ";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                blank_l = blank_r;
                blank_r = i;
                tmp = str2num(blank_l, blank_r, s);
                if (tmp > 0)
                    numbers.push_back(tmp);
            }
        }
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i] <= numbers[i - 1])
                return false;
        }
        return true;
    }
};
// @lc code=end
