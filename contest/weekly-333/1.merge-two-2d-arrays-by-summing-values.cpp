// Created by zwyyy456 at 2023/02/19 15:54
// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/
// https://leetcode.com/contest/weekly-contest-333/problems/merge-two-2d-arrays-by-summing-values/

/*
2570. Merge Two 2D Arrays by Summing Values (Easy)

You are given two **2D** integer arrays `nums1` and `nums2.`

- `nums1[i] = [idᵢ, valᵢ]` indicate that the number with the id `idᵢ` has a value equal to `valᵢ`.
- `nums2[i] = [idᵢ, valᵢ]` indicate that the number with the id `idᵢ` has a value equal to `valᵢ`.

Each array contains **unique** ids and is sorted in **ascending** order by id.

Merge the two arrays into one array that is sorted in ascending order by id, respecting the
following conditions:

- Only ids that appear in at least one of the two arrays should be included in the resulting array.
- Each id should be included **only once** and its value should be the sum of the values of this id
in the two arrays. If the id does not exist in one of the two arrays then its value in that array is
considered to be `0`.

Return the resulting array. The returned array must be sorted in ascending order by id.

**Example 1:**

```
Input: nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
Output: [[1,6],[2,3],[3,2],[4,6]]
Explanation: The resulting array contains the following:
- id = 1, the value of this id is 2 + 4 = 6.
- id = 2, the value of this id is 3.
- id = 3, the value of this id is 2.
- id = 4, the value of this id is 5 + 1 = 6.

```

**Example 2:**

```
Input: nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
Output: [[1,3],[2,4],[3,6],[4,3],[5,5]]
Explanation: There are no common ids, so we just include each id with its value in the resulting
list.

```

**Constraints:**

- `1 <= nums1.length, nums2.length <= 200`
- `nums1[i].length == nums2[j].length == 2`
- `1 <= idᵢ, valᵢ <= 1000`
- Both arrays contain unique ids.
- Both arrays are in strictly ascending order by id.
*/

// @lc code=begin
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
class Solution {
  public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2) {
        unordered_map<int, int> ump1;
        // unordered_map<int, int> ump2;
        vector<vector<int>> res;
        for (int i = 0; i < nums1.size(); i++) {
            ump1[nums1[i][0]] = nums1[i][1];
        }
        for (int i = 0; i < nums2.size(); i++) {
            ump1[nums2[i][0]] += nums2[i][1];
        }
        for (auto &num : ump1) {
            res.push_back({num.first, num.second});
        }
        std::sort(res.begin(), res.end());
        return res;
    }
};

// @lc code=end
