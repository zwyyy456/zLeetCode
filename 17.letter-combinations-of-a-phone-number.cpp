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
        if (path.size() >= n) {
            res.push_back(path);
            return;
        }
        string letters = letter_map[digits[index] - '0'];
        for (int i = 0; i < letters.size(); i++) {
            path.push_back(letters[i]);
            track_back(digits, index + 1, n);
            path.pop_back();
        }

        return;
    }

  public:
    vector<string> letterCombinations(string digits) {
        track_back(digits, 0, digits.size());
        if (res.size() == 1 && res[0] == "")
            res.clear();
        return res;
    }
};
// @lc code=end
