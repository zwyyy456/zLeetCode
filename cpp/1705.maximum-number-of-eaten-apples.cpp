// Created by Bob at 2023/02/13 18:27
// https://leetcode.com/problems/maximum-number-of-eaten-apples/

/*
1705. Maximum Number of Eaten Apples (Medium)

There is a special kind of apple tree that grows apples every day for `n` days. On the `ith` day,
the tree grows `apples[i]` apples that will rot after `days[i]` days, that is on day `i + days[i]`
the apples will be rotten and cannot be eaten. On some days, the apple tree does not grow any
apples, which are denoted by `apples[i] == 0` and `days[i] == 0`.
You decided to eat **at most** one apple a day (to keep the doctors away). Note that you can keep
eating after the first `n` days.
Given two integer arrays `days` and `apples` of length `n`, return the maximum number of apples you
can eat.
**Example 1:**
```
Input: apples = [1,2,3,5,2], days = [3,2,1,4,2]
Output: 7
Explanation: You can eat 7 apples:
- On the first day, you eat an apple that grew on the first day.
- On the second day, you eat an apple that grew on the second day.
- On the third day, you eat an apple that grew on the second day. After this day, the apples that
grew on the third day rot.
- On the fourth to the seventh days, you eat apples that grew on the fourth day.
```
**Example 2:**
```
Input: apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
Output: 5
Explanation: You can eat 5 apples:
- On the first to the third day you eat apples that grew on the first day.
- Do nothing on the fouth and fifth days.
- On the sixth and seventh days you eat apples that grew on the sixth day.
```
**Constraints:**
- `n == apples.length == days.length`
- `1 <= n <= 2 * 10⁴`
- `0 <= apples[i], days[i] <= 2 * 10⁴`
- `days[i] = 0` if and only if `apples[i] = 0`.
*/

// @lc code=begin
#include <vector>
#include <queue>
using std::priority_queue;
using std::vector;
class Solution {
  public:
    int eatenApples(vector<int> &apples, vector<int> &days) {
        // 优先吃最早腐烂的苹果，即吃腐烂日期最小的苹果
        vector<vector<int>> app_decay(apples.size(), vector<int>(2, 0));
        for (int i = 0; i < apples.size(); i++) {
            app_decay[i][0] = i + days[i];
            app_decay[i][1] = apples[i];
        }
        priority_queue<vector<int>> q;
        auto cmp = [&](vector<int> &v1, vector<int> &v2) {
            return v1[0] >= v2[0];
        };
        // 优先队列的top应该是腐烂日期最小的
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        app_decay[0][1]--;
        if (app_decay[0][1] > 0) {
            int res = 1;
            pq.push(app_decay[0]);
        }

        for (int i = 1; i < apples.size(); i++) {
            if (app_decay[i][1] != 0) {
                pq.push(app_decay[i]);
            }
            vector<int> vec;
            if (!pq.empty()) {
                vec = pq.top();
                pq.pop();
            }
            while (!pq.empty() && vec[0] <= i) {
                vec = pq.top();
                pq.pop();
            }
            if (!pq.empty()) {
                vec[1]--;
                if (vec[1] != 0) {
                    pq.push(vec);
                }
                res++;
            }
        }
        int date = apples.size();
        while (!pq.empty()) {
            auto vec1 = pq.top();
            pq.pop();
            if (vec1[0] > date) {
                vec1[1]--;
                if (vec1[1] != 0)
                    pq.push(vec1);
                res++;
            }
            date++;
        }
        return res;
    }
};

// @lc code=end
