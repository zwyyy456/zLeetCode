/*
 * @lc app=leetcode id=1774 lang=cpp
 *
 * [1774] Closest Dessert Cost
 */

// @lc code=start
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  public:
    // res表示存储的最接近target的成本，sum表示和
    int traverse(vector<int> &toppingCosts, int target, int index, int sum, int res, vector<int> &cnt) {
        if (cnt[index] > 2)
            return res;
        if (sum >= target) {
            // 返回最接近的成本
            if (abs(sum - target) < abs(target - res))
                return sum;
            else if (abs(sum - target) == abs(target - res))
                return min(res, sum);
            else
                return res;
        }
        for (int i = index; i < toppingCosts.size(); i++) {
            sum += toppingCosts[i];
            // int tmp = res;
            cnt[i]++;
            res = traverse(toppingCosts, target, i, sum, res, cnt);
            cnt[i]--;
            sum -= toppingCosts[i];
        }
        if (abs(sum - target) < abs(target - res))
            return sum;
        else if (abs(sum - target) == abs(target - res))
            return min(res, sum);
        else
            return res;
    }
    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target) {
        // 考虑使用回溯法
        int mcost = baseCosts[0];
        vector<int> cnt(toppingCosts.size(), 0);
        for (int i = 0; i < baseCosts.size(); i++) {
            if (baseCosts[i] == target)
                return target;
            else if (baseCosts[i] > target) {
                if (baseCosts[i] - target < abs(target - mcost))
                    mcost = baseCosts[i];
            } else { // 注意这里？
                int res = traverse(toppingCosts, target, 0, baseCosts[i], baseCosts[i], cnt);
                if (abs(res - target) < abs(target - mcost))
                    mcost = res;
                else if (abs(res - target) == abs(target - mcost))
                    mcost = min(res, mcost);
            }
        }
        return mcost;
    }
};
// @lc code=end
