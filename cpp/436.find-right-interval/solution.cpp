/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */

// @lc code=start
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
  public:
    int b_search(vector<int> tmp, int a, vector<vector<int>> intervals) {
        int l = 0, r = tmp.size() - 1;
        int mid = l + (r - l) / 2;
        if (a > intervals[tmp[r]][0])
            return -1;
        if (a < intervals[tmp[l]][0])
            return tmp[l];
        while (l <= r) {
            if (a == intervals[tmp[mid]][0])
                return tmp[mid];
            else if (a > intervals[tmp[mid]][0]) {
                l = mid + 1;
                mid = l + (r - l) / 2;
            } else {
                r = mid - 1;
                mid = l + (r - l) / 2;
            }
        }
        return tmp[l];
    }
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        vector<int> vec_sort(intervals.size(), 0);
        for (int i = 0; i < intervals.size(); i++) {
            vec_sort[i] = i;
        }
        std::sort(vec_sort.begin(), vec_sort.end(), [=](int a, int b) { return intervals[a][0] < intervals[b][0]; });
        vector<int> res;
        for (int i = 0; i < intervals.size(); i++) {
            res.push_back(b_search(vec_sort, intervals[i][1], intervals));
        }
        return res;
    }
};
// @lc code=end
