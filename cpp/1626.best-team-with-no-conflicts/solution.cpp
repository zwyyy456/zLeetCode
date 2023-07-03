// Created by zwyyy456 at 2023/03/22 10:10
// https://leetcode.com/problems/best-team-with-no-conflicts/

/*
1626. Best Team With No Conflicts (Medium)

You are the manager of a basketball team. For the upcoming tournament, you want to choose the team
with the highest overall score. The score of the team is the **sum** of scores of all the players in
the team.

However, the basketball team is not allowed to have **conflicts**. A **conflict** exists if a
younger player has a **strictly higher** score than an older player. A conflict does **not** occur
between players of the same age.

Given two lists, `scores` and `ages`, where each `scores[i]` and `ages[i]` represents the score and
age of the `ith` player, respectively, return the highest overall score of all possible basketball
teams.

**Example 1:**

```
Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
Output: 34
Explanation: You can choose all the players.

```

**Example 2:**

```
Input: scores = [4,5,6,5], ages = [2,1,2,1]
Output: 16
Explanation: It is best to choose the last 3 players. Notice that you are allowed to choose multiple
people of the same age.

```

**Example 3:**

```
Input: scores = [1,2,3,5], ages = [8,9,10,1]
Output: 6
Explanation: It is best to choose the first 3 players.

```

**Constraints:**

- `1 <= scores.length, ages.length <= 1000`
- `scores.length == ages.length`
- `1 <= scores[i] <= 10⁶`
- `1 <= ages[i] <= 1000`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<vector<int>> players(n, vector<int>(2, 0));
        for (int i = 0; i < n; ++i) {
            players[i][0] = ages[i];
            players[i][1] = scores[i];
        } 
        auto cmp = [&](vector<int> &v1, vector<int> &v2) {
            if (v1[0] == v2[0]) {
                return v1[1] > v2[1]; // 年龄相等时，分数从高到低
            }
            return v1[0] > v2[0]; // 按照年龄从大到小排序，为了方便动态规划
        };
        std::sort(players.begin(), players.end(), cmp);
        vector<int> dif(n);
        for (int i = 0; i < n; ++i) {
            int score_dif = 0;
            for (int j = 0; j < i; ++j) {
                if (players[j][0] > players[i][0] && players[j][1] < players[i][0]) {
                    score_dif += players[j][1];
                }
            }
            dif[i] = score_dif;
        }
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 1] + players[i - 1][1] - dif[i - 1]);
        }
        return dp[n];
    }
};

// @lc code=end
