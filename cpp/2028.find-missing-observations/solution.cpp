/*
 * @lc app=leetcode id=2028 lang=cpp
 *
 * [2028] Find Missing Observations
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
        int sum = 0;
        vector<int> res;
        for (int i = 0; i < rolls.size(); i++) {
            sum += rolls[i];
        }
        if (sum + n > mean * (rolls.size() + n) || sum + 6 * n < mean * (rolls.size() + n))
            return res;
        res.resize(n);
        int avg = (mean * (rolls.size() + n) - sum) / n;
        int cnt = (mean * (rolls.size() + n) - sum) % n;
        for (int i = 0; i < cnt; i++)
            res[i] = avg + 1;
        for (int i = cnt; i < n; i++)
            res[i] = avg;
        return res;
    }
};
// @lc code=end
