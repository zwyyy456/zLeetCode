/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
/*空间复杂度为O(m + n)
#include <vector>
using std::vector;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(m + n, 0);
        int p1 = 0, p2 = 0;
        for (int i = 0; i < m + n; i++) {
            if (p1 >= m && p2 < n)
                tmp[i] = nums2[p2++];
            else if (p2 >= n && p1 < m)
                tmp[i] = nums1[p1++];
            else {
                if (nums1[p1] > nums2[p2]) 
                    tmp[i] = nums2[p2++];
                else
                    tmp[i] = nums1[p1++];
            }   
        }
        nums1 = tmp;
    }
};
*/

// 空间复杂度为O(1)
#include <vector>
using std::vector;
class Solution {
    public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int idx = m + n - 1;
        for (int idx = m + n - 1; idx >= 0; idx--) {
            if (p1 < 0)
                nums1[idx] =  nums2[p2--];
            else if (p1 >= 0 && p2 >= 0) {
                if (nums1[p1] > nums2[p2])
                    nums1[idx] = nums1[p1--];
                else
                    nums1[idx] = nums2[p2--];
            }
        }
    }
};

// @lc code=end

