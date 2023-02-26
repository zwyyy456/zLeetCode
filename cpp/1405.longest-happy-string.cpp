// Created by Bob at 2023/02/13 09:36
// https://leetcode.com/problems/longest-happy-string/


/*
1405. Longest Happy String (Medium)

A string `s` is called **happy** if it satisfies the following conditions:
- `s` only contains the letters `'a'`, `'b'`, and `'c'`.
- `s` does not contain any of `"aaa"`, `"bbb"`, or `"ccc"` as a substring.
- `s` contains **at most** `a` occurrences of the letter `'a'`.
- `s` contains **at most** `b` occurrences of the letter `'b'`.
- `s` contains **at most** `c` occurrences of the letter `'c'`.
Given three integers `a`, `b`, and `c`, return the **longest possible happy** string. If there are
multiple longest happy strings, return any of them. If there is no such string, return the empty
string  `""`.
A **substring** is a contiguous sequence of characters within a string.
**Example 1:**
```
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
```
**Example 2:**
```
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.
```
**Constraints:**
- `0 <= a, b, c <= 100`
- `a + b + c > 0`
*/


// @lc code=begin
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
public:
    int Findmax(vector<int> &nums) {
        int idx = 0;
        for (int i = 0; i < 3; i++) {
            if (nums[i] > idx) {
                idx = i;
            }
        }
        return idx;
    }
    int FindMid(vector<int> &nums) {
        int max_num = nums[0];
        int min_num = nums[0];
        for (int i = 1; i < 3; i++) {
            if (nums[i] > max_num)
                max_num = nums[i];
            if (nums[i] < min_num)
                min_num = nums[i];
        }
        for (int i = 0; i < 3; i++) {
            if (nums[i] <= max_num && nums[i] >= min_num)
                return i;
        }
        return 0;
    }
    string longestDiverseString(int a, int b, int c) {
        vector<int> num{a, b, c};
        vector<char> ch{'a', 'b', 'c'};
        vector<int> cnt{0, 0, 0};
        int sum = a + b + c;
        string res;
        for (int i = 0; i < sum; i++) {
            int idx_max = Findmax(num);
            int idx_mid = FindMid(num);
            if (cnt[idx_max] < 2) {
                res.push_back(ch[idx_max]);
                num[idx_max]--;
                cnt[idx_max]++;
                cnt[idx_mid] = 0;
            } else {
                res.push_back(ch[idx_mid]);
                num[idx_mid]++;
                
            }

        }
    }
};

// @lc code=end

