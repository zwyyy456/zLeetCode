/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start

#include <vector>
#include <algorithm>
using std::vector;
class Solution {
    private:
    vector<int> path;
    vector<vector<int>> res;
    int sum = 0;
    void track_back(vector<int> &candidates, int target, int index) {
        // int sum = 0;
        // for (int i = 0; i < path.size(); i++)
        //     sum += path[i];
        if (sum > target)
            return;
        else if (sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);//当 sum =6, path(2,2,2）

            track_back(candidates, target, i);
            sum -= candidates[i];
            //sum -= candidates[i];
            //path.pop_back();
            path.pop_back();

            // track_back(candidates, target, i + 1);
            // sum -= candidates[i + 1];
            // path.pop_back();
            // //sum -= candidates[i];
            // //path.pop_back();
            
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        track_back(candidates, target, 0);
        return res;
    }
};
// @lc code=end

