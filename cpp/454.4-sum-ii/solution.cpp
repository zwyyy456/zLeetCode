/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;
class Solution {
  public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        unordered_map<int, int> map12, map34;
        int count = 0;
        int sum, sum2;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                sum = nums1[i] + nums2[j];
                map12[sum]++;
            }
        }
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                sum2 = nums3[i] + nums4[j];
                map34[sum2]++;
            }
        }
        for (const auto &m : map12) {
            if (map34.find(0 - m.first) != map34.end()) {
                count += map34[0 - m.first] * m.second;
            }
        }
        return count;
    }
};
// @lc code=end
