// Created by Bob at 2023/02/09 20:14
// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

/*
1996. The Number of Weak Characters in the Game (Medium)

You are playing a game that contains multiple characters, and each of the characters has **two**
main properties: **attack** and **defense**. You are given a 2D integer array `properties` where
`properties[i] = [attackᵢ, defenseᵢ]` represents the properties of the `ith` character in the game.
A character is said to be **weak** if any other character has **both** attack and defense levels
**strictly greater** than this character's attack and defense levels. More formally, a character `i`
is said to be **weak** if there exists another character `j` where `attackⱼ > attackᵢ` and `defenseⱼ
> defenseᵢ`.
Return the number of **weak** characters.
**Example 1:**
```
Input: properties = [[5,5],[6,3],[3,6]]
Output: 0
Explanation: No character has strictly greater attack and defense than the other.
```
**Example 2:**
```
Input: properties = [[2,2],[3,3]]
Output: 1
Explanation: The first character is weak because the second character has a strictly greater attack
and defense.
```
**Example 3:**
```
Input: properties = [[1,5],[10,4],[4,3]]
Output: 1
Explanation: The third character is weak because the second character has a strictly greater attack
and defense.
```
**Constraints:**
- `2 <= properties.length <= 10⁵`
- `properties[i].length == 2`
- `1 <= attackᵢ, defenseᵢ <= 10⁵`
*/

// @lc code=begin
#include <string>
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
  public:
    int numberOfWeakCharacters(vector<vector<int>> &properties) {
        std::sort(properties.begin(), properties.end(), [&](vector<int> &vec1, vector<int> &vec2) {
            if (vec1[0] == vec2[0])
                return vec1[1] <= vec2[1];
            return vec1[0] > vec2[0];
        });
        int cnt = 0;
        int attack_max = properties[0][0];
        int defend_max = properties[0][1];
        for (int i = 1; i < properties.size(); i++) {
            if (properties[i][0] < attack_max && properties[i][1] < defend_max) {
                cnt++;
            } else if (properties[i][1] > defend_max) {
                defend_max = properties[i][1];
            }
        }
        return cnt;
    }
};
// @lc code=end
