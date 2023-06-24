/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  private:
    int max(int a, int b) {
        return a > b ? a : b;
    }

  public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = 0;
        vector<int> my_num(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            my_num[i + 1] = nums[i];
        }
        if ((sum + target) % 2 == 1)
            return 0;
        vector<int> res(1001, 0);
        res[0] = 1;
        target = max((sum + target) / 2, (sum - target) / 2);
        // int cnt = 0;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = target; j >= my_num[i]; j--) {
                // if (my_num[i] == 0)
                //     res[j] = res[j] + 1;
                // else
                //     res[j] = max(res[j], res[j - my_num[i]]);
                res[j] = res[j] + res[j - my_num[i]];
            }
        }
        return res[target];
    }
};

/*
    track_back
*/
// class Solution {
//   private:
//     int cnt = 0;
//     int sum = 0;
//     void track_back(vector<int> &nums, int target, int index) {
//         if (index >= nums.size())
//             return;
//         for (int i = index; i < nums.size(); i++) {
//             sum += nums[i];
//             if (sum == target)
//                 cnt++;
//             track_back(nums, target, i + 1);
//             sum -= nums[i];
//         }
//         return;
//     }

//   public:
//     int findTargetSumWays(vector<int> &nums, int target) {
//         int num_sum = 0;
//         for (int i = 0; i < nums.size(); i++)
//             num_sum += nums[i];
//         if ((num_sum + target) % 2 == 1)
//             return 0;
//         target = (num_sum + target) / 2;
//         if (sum == target)
//             cnt++;
//         track_back(nums, target, 0);
//         return cnt;
//     }
// };
// @lc code=end
