// Created by zwyyy456 at 2023/03/06 11:37
// https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/

/*
1744. Can You Eat Your Favorite Candy on Your Favorite Day? (Medium)

You are given a **(0-indexed)** array of positive integers `candiesCount` where `candiesCount[i]`
represents the number of candies of the `ith` type you have. You are also given a 2D array `queries`
where `queries[i] = [favoriteTypeᵢ, favoriteDayᵢ, dailyCapᵢ]`.

You play a game with the following rules:

- You start eating candies on day `0`.
- You **cannot** eat **any** candy of type `i` unless you have eaten **all** candies of type `i -
1`.
- You must eat **at least** **one** candy per day until you have eaten all the candies.

Construct a boolean array `answer` such that `answer.length == queries.length` and `answer[i]` is
`true` if you can eat a candy of type `favoriteTypeᵢ` on day `favoriteDayᵢ` without eating **more
than** `dailyCapᵢ` candies on **any** day, and `false` otherwise. Note that you can eat different
types of candy on the same day, provided that you follow rule 2.

Return the constructed array  `answer`.

**Example 1:**

```
Input: candiesCount = [7,4,5,3,8], queries = [[0,2,2],[4,2,4],[2,13,1000000000]]
Output: [true,false,true]
Explanation:
1- If you eat 2 candies (type 0) on day 0 and 2 candies (type 0) on day 1, you will eat a candy of
type 0 on day 2.
2- You can eat at most 4 candies each day.
   If you eat 4 candies every day, you will eat 4 candies (type 0) on day 0 and 4 candies (type 0
and type 1) on day 1.
   On day 2, you can only eat 4 candies (type 1 and type 2), so you cannot eat a candy of type 4 on
day 2.
3- If you eat 1 candy each day, you will eat a candy of type 2 on day 13.

```

**Example 2:**

```
Input: candiesCount = [5,2,6,4,1], queries = [[3,1,2],[4,10,3],[3,10,100],[4,100,30],[1,3,1]]
Output: [false,true,true,false,false]

```

**Constraints:**

- `1 <= candiesCount.length <= 10⁵`
- `1 <= candiesCount[i] <= 10⁵`
- `1 <= queries.length <= 10⁵`
- `queries[i].length == 3`
- `0 <= favoriteTypeᵢ < candiesCount.length`
- `0 <= favoriteDayᵢ <= 10⁹`
- `1 <= dailyCapᵢ <= 10⁹`
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
  public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries) {
        vector<long> prefix(candiesCount.size() + 1, 0);
        vector<bool> ans(queries.size(), 0);
        for (int i = 1; i <= candiesCount.size(); ++i) {
            prefix[i] = prefix[i - 1] + candiesCount[i - 1];
        }
        for (int i = 0; i < queries.size(); ++i) {
            int type = queries[i][0];
            int fday = queries[i][1];
            int cap = queries[i][2];
            // 要求fday天吃到type， 考虑吃不到的情况
            // fday天，就算吃最多，也吃不到type
            // 假设fday = 6，前面0，1，2，。。。已经吃了6天，type = 4，想吃到第四种，就要吃0，1，2，3前面4种
            if ((long)(fday + 1) * cap <= prefix[type]) {
                ans[i] = false;
            } else if (prefix[type + 1] <= fday) {
                // 假设每天只吃1颗，也会提前吃完
                // 假设fday=6,type=4，那么前面吃了fday=6个，如果prefix[type+1] <= 6，此时0，1，2，3，4种都吃掉了
                // 第6天只能吃type=5了
                ans[i] = false;
            } else {
                ans[i] = true;
            }
        }
        return ans;
    }
};

// @lc code=end
