// Created by zwyyy456 at 2023/02/25 08:46
// https://leetcode.com/problems/boats-to-save-people/

/*
881. Boats to Save People (Medium)

You are given an array `people` where `people[i]` is the weight of the `ith` person, and an
**infinite number of boats** where each boat can carry a maximum weight of `limit`. Each boat
carries at most two people at the same time, provided the sum of the weight of those people is at
most `limit`.

Return the minimum number of boats to carry every given person.

**Example 1:**

```
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)

```

**Example 2:**

```
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)

```

**Example 3:**

```
Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)

```

**Constraints:**

- `1 <= people.length <= 5 * 10⁴`
- `1 <= people[i] <= limit <= 3 * 10⁴`
*/

// @lc code=begin
#include <functional>
#include <vector>
#include <map>
using std::vector;
using std::map;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        map<int, int, std::greater<int>> mp;
        for (auto &weight : people) {
            mp[weight]++;
        }
        int cnt = 0;
        for (auto weight : people) {
            if (mp.empty()) {
                return cnt;
            }
            if (mp.find(weight) != mp.end()) {
                auto iter = mp.lower_bound(limit - weight);
                if (iter != mp.end()) {
                    cnt++;
                    mp[weight]--;
                    if (mp[weight] == 0) {
                        mp.erase(weight);
                    }
                    iter->second--;
                    if (iter->second == 0) {
                        mp.erase(iter);
                    }
                } else {
                    cnt++;
                    mp[weight]--;
                    if (mp[weight] == 0) {
                        mp.erase(weight);
                    }
                }
            } 
        }
        return cnt;
    }
};

// @lc code=end
