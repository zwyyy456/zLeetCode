/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int gas_sum = 0;
        int cost_sum = 0;
        int sum = 0;
        int sum_index = 0;
        vector<int> diff(gas.size(), 0);
        for (int i = 0; i < gas.size(); i++) {
            gas_sum += gas[i];
            cost_sum += cost[i];
            diff[i] = gas[i] - cost[i];
        }
        if (cost_sum > gas_sum)
            return -1;
        int i = 0;
        while (i < gas.size()) {
            if (diff[i] <= 0)
                i++;
            else {
                if (diff[i] > 0) {
                    sum_index = i;
                    // sum = diff[i];
                }
                while (sum >= 0 && i < gas.size())
                    sum += diff[i++];
                if (i < gas.size() && diff[i] > 0) {
                    // sum_index = i;
                    sum = 0;
                }
            }
        }
        return sum_index;
    }
};
// @lc code=end
