/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
    private:
    vector<int> path;
    vector<vector<int>> res;
    void back_track(vector<int> &candidates, int target) {
        int sum = 0;
        for (int i = 0; i < path.size(); i++) {
            sum += path[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
    }
};
// @lc code=end

