/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
#include <stack>
#include <unordered_map>
#include <vector>
using std::stack;
using std::unordered_map;
using std::vector;
class Solution {
  public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> umap;
        stack<int> stk;
        for (int i = 0; i < nums1.size(); i++) {
            umap.insert({nums1[i], -1});
        }
        stk.push(0);
        for (int i = 1; i < nums2.size(); i++) {
            while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
                if (umap.find(nums2[stk.top()]) != umap.end()) {
                    umap[nums2[stk.top()]] = nums2[i];
                }
                stk.pop();
            }
            stk.push(i);
        }
        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            res[i] = umap[nums1[i]];
        }
        return res;
    }
};
// @lc code=end
