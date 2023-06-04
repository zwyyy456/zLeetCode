// Created by zwyyy456 at 2023/05/19 09:46
// https://leetcode.com/problems/letter-tile-possibilities/

/*
1079. Letter Tile Possibilities (Medium)
You have `n` `tiles`, where each tile has one letter `tiles[i]` printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed
on those `tiles`.

**Example 1:**

```
Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

```

**Example 2:**

```
Input: tiles = "AAABBC"
Output: 188

```

**Example 3:**

```
Input: tiles = "V"
Output: 1

```

**Constraints:**

- `1 <= tiles.length <= 7`
- `tiles` consists of uppercase English letters.

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    void dfs(unordered_map<char, int> &chars, unordered_set<string> &res, string &tmp) {
        // if (chars.empty()) {
        // 	return;
        // }
        for (auto pai : chars) {
            if (pai.second == 0) {
                continue;
                ;
            }
            tmp.push_back(pai.first);
            if (res.find(tmp) == res.end()) {
                res.insert(tmp);
            }
            --chars[pai.first];
            dfs(chars, res, tmp);
            tmp.pop_back();
            ++chars[pai.first];
        }
    }
    int numTilePossibilities(string tiles) {
        // 回溯，找出所有排列方式？
        unordered_map<char, int> chars;
        for (char c : tiles) {
            ++chars[c];
        }
        // 能不能直接算出来
        unordered_set<string> res;
        string tmp;
        dfs(chars, res, tmp);
        return res.size();
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string tiles;
    LeetCodeIO::scan(cin, tiles);

    Solution *obj = new Solution();

    auto res = obj->numTilePossibilities(tiles);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
