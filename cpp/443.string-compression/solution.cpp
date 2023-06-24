/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
  public:
    int compress(vector<char> &chars) {
        vector<char> res;
        int cnt = 0;
        for (int slow = 0, fast = 0; fast < chars.size();) {
            while (fast < chars.size() && chars[fast] == chars[slow])
                fast++;
            cnt = fast - slow;
            if (cnt == 1)
                res.push_back(chars[slow]);
            else if (cnt > 1 && cnt <= 9) {
                res.push_back(chars[slow]);
                res.push_back(cnt + '0');
            } else if (cnt >= 10 && cnt <= 99) {
                res.push_back(chars[slow]);
                res.push_back(cnt / 10 + '0');
                res.push_back(cnt % 10 + '0');
            } else if (cnt >= 100 && cnt <= 999) {
                res.push_back(chars[slow]);
                res.push_back(cnt / 100 + '0');
                res.push_back((cnt % 100) / 10 + '0');
                res.push_back((cnt % 100) % 10 + '0');
            } else {
                res.push_back(chars[slow]);
                res.push_back(cnt / 1000 + '0');
                res.push_back((cnt % 1000) / 100 + '0');
                res.push_back((cnt % 1000) % 100 / 10 + '0');
                res.push_back(cnt % 1000 % 100 % 10 + '0');
            }
            slow = fast;
        }
        chars = res;
        return res.size();
    }
};
// @lc code=end
