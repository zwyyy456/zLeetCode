/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
  private:
    string path;
    vector<string> res;
    string letter_map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    // n为digits的长度
    void track_back(string digits, int index, int n) {
        if (path.size() == n) {
            res.push_back(path);
            return;
        }

        for (char c : letter_map[digits[index] - '0']) {
            path.push_back(c);
            track_back(digits, index + 1, n);
            path.pop_back();
        }

        return;
    }

  public:
    vector<string> letterCombinations(string digits) {
        track_back(digits, 0, digits.size());
        return res;
    }
};
// @lc code=end
