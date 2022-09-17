/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using std::vector;
class Solution {
    private:
    int sum = 0;
    vector<int> path;
    vector<vector<int>> res;
    void track_back(vector<int> &candidates, int target, int index) {
        if (sum == target) {
            res.push_back(path);
            return;
        } else if (sum > target)
        {
            return;
        }
        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // if (i >= 1 && candidates[i] == candidates[i - 1] && candidates[i] != path[i - 1])
            //     continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            track_back(candidates, target, i + 1);
            sum -= candidates[i];
            path.pop_back();
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
                i++;
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        track_back(candidates, target, 0);
        return res;
    }
};
// @lc code=end

