/*
 * @lc app=leetcode id=1945 lang=cpp
 *
 * [1945] Sum of Digits of String After Convert
 */

// @lc code=start
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
  public:
    int getLucky(string s, int k) {
        vector<int> num;
        int tmp = 0;
        int sum = 0;
        for (char c : s) {
            tmp = c - 'a' + 1;
            if (tmp / 10) {
                num.push_back(tmp / 10);
                sum += tmp / 10;
            }
            num.push_back(tmp % 10);
            sum += tmp % 10;
        }
        int res_sum = 0;
        for (int i = 1; i < k; i++) {
            while (sum != 0) {
                res_sum += sum % 10;
                sum = sum / 10;
            }
            sum = res_sum;
            res_sum = 0;
        }
        return sum;
    }
};
// @lc code=end
