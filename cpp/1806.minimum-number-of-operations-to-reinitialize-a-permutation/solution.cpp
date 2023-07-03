/*
 * @lc app=leetcode id=1806 lang=cpp
 *
 * [1806] Minimum Number of Operations to Reinitialize a Permutation
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  public:
    int reinitializePermutation(int n) {
        vector<int> examples(n);
        vector<int> perm(n);
        vector<int> arr(n);
        int ops = 0;
        int flag_sum = 0;
        for (int i = 0; i < n; i++) {
            examples[i] = i;
            perm[i] = i;
        }
        while (flag_sum < n) {
            flag_sum = 0;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0)
                    arr[i] = perm[i / 2];
                else
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                if (arr[i] == examples[i])
                    flag_sum++;
            }
            perm.assign(arr.begin(), arr.end());
            ops++;
        }
        return ops;
    }
};
// @lc code=end
