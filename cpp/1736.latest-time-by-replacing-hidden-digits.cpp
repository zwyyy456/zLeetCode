// Created by Bob at 2023/02/18 15:20
// https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/

/*
1736. Latest Time by Replacing Hidden Digits (Easy)

You are given a string `time` in the form of ` hh:mm`, where some of the digits in the string are
hidden (represented by `?`).
The valid times are those inclusively between `00:00` and `23:59`.
Return the latest valid time you can get from `time` by replacing the hiddendigits.
**Example 1:**
```
Input: time = "2?:?0"
Output: "23:50"
Explanation: The latest hour beginning with the digit '2' is 23 and the latest minute ending with
the digit '0' is 50.
```
**Example 2:**
```
Input: time = "0?:3?"
Output: "09:39"
```
**Example 3:**
```
Input: time = "1?:22"
Output: "19:22"
```
**Constraints:**
- `time` is in the format `hh:mm`.
- It is guaranteed that you can produce a valid time from the given string.
*/

// @lc code=begin
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
