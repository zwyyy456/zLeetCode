/*
 * @lc app=leetcode id=768 lang=cpp
 *
 * [768] Max Chunks To Make Sorted II
 */

// @lc code=start
#include <map>
#include <vector>
using std::map;
using std::vector;
class Solution {
  public:
    int maxChunksToSorted(vector<int> &arr) {
        int idx = 0; // 表示划分arr
        int ans = 0;
        map<int, int, std::greater<int>> l_map;
        map<int, int> r_map;
        for (int i = 0; i < arr.size(); i++)
            r_map[arr[i]]++;
        while (idx < arr.size()) {
            for (int i = idx; i < arr.size(); i++) {
                l_map[arr[i]]++;
                r_map[arr[i]]--;
                if (r_map[arr[i]] == 0)
                    r_map.erase(arr[i]);
                if (r_map.empty())
                    break;
                if (l_map.begin()->first <= r_map.begin()->first) {
                    idx = i + 1;
                    ans++;
                    break;
                }
            }
            if (r_map.empty()) {
                ans++;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
