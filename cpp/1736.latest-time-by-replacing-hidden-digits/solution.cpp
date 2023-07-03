/*
 * @lc app=leetcode id=1736 lang=cpp
 *
 * [1736] Latest Time by Replacing Hidden Digits
 */

// @lc code=start
#include <string>
using std::string;
class Solution {
  public:
    string maximumTime(string time) {
        string res;
        // 先考虑小时
        if (time[0] == '?') {
            if (time[1] == '?')
                res += "23";
            else {
                if (time[1] >= '4') {
                    res.push_back('1');
                    res.push_back(time[1]);
                } else {
                    res.push_back('2');
                    res.push_back(time[1]);
                }
            }
        } else {
            if (time[1] == '?') {
                if (time[0] == '2') {
                    res.push_back(time[0]);
                    res.push_back('3');
                } else {
                    res.push_back(time[0]);
                    res.push_back('9');
                }
            } else {
                res.push_back(time[0]);
                res.push_back(time[1]);
            }
        }
        res.push_back(time[2]);
        // 再考虑分钟
        if (time[3] == '?') {
            if (time[4] == '?')
                res += "59";
            else {
                res.push_back('5');
                res.push_back(time[4]);
            }
        } else {
            if (time[4] == '?') {
                res.push_back(time[3]);
                res.push_back('9');
            } else {
                res.push_back(time[3]);
                res.push_back(time[4]);
            }
        }
        return res;
    }
};
// @lc code=end
