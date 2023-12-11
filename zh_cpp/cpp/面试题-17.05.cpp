// Created by Bob at 2023/03/11 11:48
// https://leetcode.cn/problems/find-longest-subarray-lcci/

/*
面试题 17.05.  字母与数字 (Medium)

给定一个放有字母和数字的数组，找到最长的子数组，且包含的字母和数字的个数相同。

返回该子数组，若存在多个最长子数组，返回左端点下标值最小的子数组。若不存在这样的数组，返回一个空数组。

**示例 1:**

```
输入:
["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]

输出:
["A","1","B","C","D","2","3","4","E","5","F","G","6","7"]

```

**示例 2:**

```
输入: ["A","A"]

输出: []

```

**提示：**

- `array.length <= 100000`
*/

// @lc code=begin
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::string;
class Solution {
  public:
    vector<string> findLongestSubarray(vector<string> &array) {
        int n = array.size();
        vector<string> res;
        if (n < 2) {
            return res;
        }
        unordered_set<string> ust;
        for (char c = 'a'; c <= 'z'; c++) { // 统计所有的字母
            string s(1, c);
            ust.insert(s);
        }
        for (char c = 'A'; c <= 'Z'; c++) {
            string s(1, c);
            ust.insert(s);
        }
        unordered_map<int, int> ump;
        ump[0] = 0;
        int len = 0;
        int idx = 0;
        vector<int> prefix(n + 1); // prefix[i]表示前i个数里，数字的数量减去字母的数量
        for (int i = 1; i <= n; ++i) {
            if (ust.find(array[i - 1]) == ust.end()) {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1] - 1;
            }
            if (ump.find(prefix[i]) != ump.end()) { // 说明存在以i - 1为右端点的子数组
                if (len < i - ump[prefix[i]]) {
                    len = i - ump[prefix[i]];
                    idx = ump[prefix[i]];
                }
            } else {
                ump[prefix[i]] = i;
            }
        }
        res.resize(len);
        for (int i = idx; i < idx + len; ++i) {
            res[i - idx] = array[i];
        }
        return res;
    }
};
// @lc code=end
