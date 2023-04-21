// Created by zwyyy456 at 2023/04/15 14:41
// https://leetcode.com/problems/flower-planting-with-no-adjacent/

/*
1042. Flower Planting With No Adjacent (Medium)

You have `n` gardens, labeled from `1` to `n`, and an array `paths` where `paths[i] = [xᵢ, yᵢ]`
describes a bidirectional path between garden `xᵢ` to garden `yᵢ`. In each garden, you want to plant
one of 4 types of flowers.

All gardens have **at most 3** paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a
path, they have different types of flowers.

Return **any** such a choice as an array  `answer`, where  `answer[i]` is the type of flower planted
in the  `(i+1)th` garden. The flower types are denoted  `1`,  `2`,  `3`, or  `4`. It is guaranteed
an answer exists.

**Example 1:**

```
Input: n = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Explanation:
Gardens 1 and 2 have different types.
Gardens 2 and 3 have different types.
Gardens 3 and 1 have different types.
Hence, [1,2,3] is a valid answer. Other valid answers include [1,2,4], [1,4,2], and [3,2,1].

```

**Example 2:**

```
Input: n = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]

```

**Example 3:**

```
Input: n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]

```

**Constraints:**

- `1 <= n <= 10⁴`
- `0 <= paths.length <= 2 * 10⁴`
- `paths[i].length == 2`
- `1 <= xᵢ, yᵢ <= n`
- `xᵢ != yᵢ`
- Every garden has **at most 3** paths coming into or leaving it.
*/

// @lc code=begin
#include <vector>
using std::vector;
class Solution {
public:
    vector<int> ans;
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n + 1);
        for (auto &vec : paths) {
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }
        vector<int> color(n, 0); // 为0表示还没有种花
        for (int i = 0; i < n; ++i) {
            vector<bool> used(5, false);
            for (auto &v : graph[i]) {
                used[ans[v]] = true;
            }
            for (int j = 1; j <= 4; ++j) {
                if (!used[j]) {
                    ans[i] = j;
                    break;
                }
            }
        }
        return color;
    }
};

// @lc code=end
