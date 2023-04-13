// Created by zwyyy456 at 2023/04/10 12:03
// https://leetcode.com/problems/loud-and-rich/

/*
851. Loud and Rich (Medium)

There is a group of `n` people labeled from `0` to `n - 1` where each person has a different amount
of money and a different level of quietness.

You are given an array `richer` where `richer[i] = [aᵢ, bᵢ]` indicates that `aᵢ` has more money than
`bᵢ` and an integer array `quiet` where `quiet[i]` is the quietness of the `ith` person. All the
given data in richer are **logically correct** (i.e., the data will not lead you to a situation
where `x` is richer than `y` and `y` is richer than `x` at the same time).

Return an integer array  `answer` where  `answer[x] = y` if  `y` is the least quiet person (that is,
the person  `y` with the smallest value of  `quiet[y]`) among all people who definitely have equal
to or more money than the person  `x`.

**Example 1:**

```
Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
Output: [5,5,2,5,4,5,6,7]
Explanation:
answer[0] = 5.
Person 5 has more money than 3, which has more money than 1, which has more money than 0.
The only person who is quieter (has lower quiet[x]) is person 7, but it is not clear if they have
more money than person 0.
answer[7] = 7.
Among all people that definitely have equal to or more money than person 7 (which could be persons
3, 4, 5, 6, or 7), the person who is the quietest (has lower quiet[x]) is person 7.
The other answers can be filled out with similar reasoning.

```

**Example 2:**

```
Input: richer = [], quiet = [0]
Output: [0]

```

**Constraints:**

- `n == quiet.length`
- `1 <= n <= 500`
- `0 <= quiet[i] < n`
- All the values of `quiet` are **unique**.
- `0 <= richer.length <= n * (n - 1) / 2`
- `0 <= aᵢ, bᵢ < n`
- `aᵢ != bᵢ`
- All the pairs of `richer` are **unique**.
- The observations in `richer` are all logically consistent.
*/

// @lc code=begin
#include <queue>
#include <vector>
using std::vector;
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        // 拓扑排序，然后一次遍历
        // 利用优先队列进行bfs
        int n = quiet.size();
        // 更rich的排在拓扑序列的后面，先构建直接相连的图
        vector<vector<int>> graph(n);
        vector<int> in(n);
        for (auto &vec : richer) {
            graph[vec[0]].push_back(vec[1]);
            ++in[vec[1]];
        }
        std::queue<int> in0;
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                in0.push(i);
            }
            res[i] = i;
        }
        while (!in0.empty()) {
            auto idx = in0.front();
            in0.pop();
            for (auto v : graph[idx]) {
                if (quiet[res[idx]] < quiet[res[v]]) {
                    res[v] = res[idx];
                }
                if (--in[v] == 0) {
                    in0.push(v);
                }
            }
        }
        return res;
    }
};
// @lc code=end
