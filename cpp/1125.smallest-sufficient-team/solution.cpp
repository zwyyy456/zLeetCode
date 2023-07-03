// Created by zwyyy456 at 2023/04/08 20:01
// https://leetcode.com/problems/smallest-sufficient-team/

/*
1125. Smallest Sufficient Team (Hard)

In a project, you have a list of required skills `req_skills`, and a list of people. The `ith`
person `people[i]` contains a list of skills that the person has.

Consider a sufficient team: a set of people such that for every required skill in `req_skills`,
there is at least one person in the team who has that skill. We can represent these teams by the
index of each person.

- For example, `team = [0, 1, 3]` represents the people with skills `people[0]`, `people[1]`, and
`people[3]`.

Return any sufficient team of the smallest possible size, represented by the index of each person.
You may return the answer in **any order**.

It is **guaranteed** an answer exists.

**Example 1:**

```
Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]

```

**Example 2:**

```
Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people =
[["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]

```

**Constraints:**

- `1 <= req_skills.length <= 16`
- `1 <= req_skills[i].length <= 16`
- `req_skills[i]` consists of lowercase English letters.
- All the strings of `req_skills` are **unique**.
- `1 <= people.length <= 60`
- `0 <= people[i].length <= 16`
- `1 <= people[i][j].length <= 16`
- `people[i][j]` consists of lowercase English letters.
- All the strings of `people[i]` are **unique**.
- Every skill in `people[i]` is a skill in `req_skills`.
- It is guaranteed a sufficient team exists.
*/

// @lc code=begin
#include <vector>
#include <unordered_map>
#include <string>
using std::unordered_map;
using std::string;
using std::vector;

class Solution {
  public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people) {
        int n = req_skills.size();
        std::unordered_map<string, int> ump;
        for (int i = 0; i < n; ++i) {
            ump[req_skills[i]] = i;
        }
        long m = people.size();
        vector<int> vec(m);
        for (int i = 0; i < m; ++i) {
            for (auto &str : people[i]) {
                if (ump.find(str) != ump.end()) {
                    vec[i] |= (1 << ump[str]);
                }
            }
        }
        int cnt = m;
        vector<vector<int>> dp(1 << n, vector<int>(m + 1, 200));
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = 0;
        }
        vector<vector<long>> res(1 << n, vector<long>(m + 1, ((long)1 << m) - 1));
        for (int j = 0; j <= m; ++j) {
            res[0][j] = 0;
        }
        // for (int i = 0; i < (1 << n); ++i) {
        //     res[i] = i;
        // }
        for (int i = 1; i < 1 << n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int cnt1 = dp[i][j - 1];                        // 不选第j个人
                int cnt2 = dp[i ^ (i & vec[j - 1])][j - 1] + 1; // 选第j个人
                if (cnt1 > cnt2) {
                    dp[i][j] = cnt2;
                    res[i][j] = res[i ^ (i & vec[j - 1])][j - 1] | ((long)1 << (j - 1)); // 即选第j个人对应的res[i]
                } else {
                    dp[i][j] = cnt1;
                    res[i][j] = res[i][j - 1];
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            if ((((long)1 << i) & res[(1 << n) - 1][m]) != 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end
