/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
        std::sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &vec1, vector<int> &vec2) { return vec1[1] >= vec2[1]; });
        int cnt = 0, sum = 0;
        for (int i = 0; i < boxTypes.size(); i++) {
            if (cnt + boxTypes[i][0] <= truckSize) {
                sum += boxTypes[i][0] * boxTypes[i][1];
                cnt += boxTypes[i][0];
            } else {
                sum += (truckSize - cnt) * boxTypes[i][1];
                break;
            }
        }
        return sum;
    }
};
// @lc code=end
