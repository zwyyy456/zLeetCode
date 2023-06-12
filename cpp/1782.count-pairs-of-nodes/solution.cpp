// Created by zwyyy456 at 2023/06/11 15:49
// https://leetcode.com/problems/count-pairs-of-nodes/

/*
1782. Count Pairs Of Nodes (Hard)
You are given an undirected graph defined by an integer `n`, the number of nodes, and a 2D integer
array `edges`, the edges in the graph, where `edges[i] = [uᵢ, vᵢ]` indicates that there is an
**undirected** edge between `uᵢ` and `vᵢ`. You are also given an integer array `queries`.

Let `incident(a, b)` be defined as the **number of edges** that are connected to **either** node `a`
or `b`.

The answer to the `jth` query is the **number of pairs** of nodes `(a, b)` that satisfy **both** of
the following conditions:

- `a < b`
- `incident(a, b) > queries[j]`

Return an array  `answers` such that  `answers.length == queries.length` and  `answers[j]` is the
answer of the  `jth` query.

Note that there can be **multiple edges** between the same two nodes.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/06/08/winword_2021-06-08_00-58-39.png)

```
Input: n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]], queries = [2,3]
Output: [6,5]
Explanation: The calculations for incident(a, b) are shown in the table above.
The answers for each of the queries are as follows:
- answers[0] = 6. All the pairs have an incident(a, b) value greater than 2.
- answers[1] = 5. All the pairs except (3, 4) have an incident(a, b) value greater than 3.

```

**Example 2:**

```
Input: n = 5, edges = [[1,5],[1,5],[3,4],[2,5],[1,3],[5,1],[2,3],[2,5]], queries = [1,2,3,4,5]
Output: [10,10,9,8,6]

```

**Constraints:**

- `2 <= n <= 2 * 10⁴`
- `1 <= edges.length <= 10⁵`
- `1 <= uᵢ, vᵢ <= n`
- `uᵢ != vᵢ`
- `1 <= queries.length <= 20`
- `0 <= queries[j] < edges.length`

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n; LeetCodeIO::scan(cin, n);
	vector<vector<int>> edges; LeetCodeIO::scan(cin, edges);
	vector<int> queries; LeetCodeIO::scan(cin, queries);

	Solution *obj = new Solution();

	auto res = obj->countPairs(n, edges, queries);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
