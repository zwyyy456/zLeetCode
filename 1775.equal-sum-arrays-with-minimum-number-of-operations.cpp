/*
 * @lc app=leetcode id=1775 lang=cpp
 *
 * [1775] Equal Sum Arrays With Minimum Number of Operations
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;
class Solution {
  public:
    int find_min(vector<int> &v) {
        for (int i = 1; i < v.size(); i++) {
            if (v[i] != 0)
                return i;
        }
        return 6;
    }
    int find_max(vector<int> &v) {
        for (int i = v.size() - 1; i >= 1; i--) {
            if (v[i] != 0)
                return i;
        }
        return 1;
    }
    int minOperations(vector<int> &nums1, vector<int> &nums2) {
        int sum1 = 0, sum2 = 0;
        vector<int> mp1(7, 0);
        vector<int> mp2(7, 0);
        if (nums1.size() > 6 * nums2.size() || 6 * nums1.size() < nums2.size())
            return -1;
        for (int i = 0; i < nums1.size(); i++) {
            mp1[nums1[i]]++;
            sum1 += nums1[i];
        }
        for (int i = 0; i < nums2.size(); i++) {
            mp2[nums2[i]]++;
            sum2 += nums2[i];
        }
        int diff = sum1 - sum2;
        int cnt = 0;
        if (diff == 0)
            return cnt;
        else if (diff > 0) {
            // 对nums1, 移动一次最多减少 find_max(mp1) - 1;
            // 对nums2, 移动一次最多增加 6 - find_min(mp2);
            while (diff > 0) {
                cnt++;
                int minus1 = find_max(mp1) - 1;
                int plus2 = 6 - find_min(mp2);
                if (minus1 >= plus2) {
                    diff -= minus1;
                    mp1[find_max(mp1)]--;
                } else {
                    diff -= 6 - find_min(mp2);
                    mp2[find_min(mp2)]--;
                }
            }
            return cnt;
        } else {
            // 对nums1, 移动一次最多增加 6 - find_min(mp1);
            // 对nums2, 移动一次最多减少 find_max(mp2) - 1;
            while (diff < 0) {
                cnt++;
                int minus2 = find_max(mp2) - 1;
                int plus1 = 6 - find_min(mp1);
                if (minus2 >= plus1) {
                    diff += minus2;
                    mp2[find_max(mp2)]--;
                } else {
                    diff += plus1;
                    mp1[find_min(mp1)]--;
                }
            }
            return cnt;
        }
    }
};
// @lc code=end
