/*
 * @lc app=leetcode id=738 lang=cpp
 *
 * [738] Monotone Increasing Digits
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
  private:
    void vec_dec(int n, vector<int> &res) {
        while (n != 0) {
            res.push_back(n % 10);
            n = n / 10;
        }
    }
    int ten(int i) {
        int res = 1;
        while (i != 0) {
            i--;
            res *= 10;
        }
        return res;
    }

  public:
    int monotoneIncreasingDigits(int n) {
        vector<int> dec;
        vec_dec(n, dec);
        std::reverse(dec.begin(), dec.end());
        if (dec.size() <= 1)
            return n;
        for (int i = 0; i < dec.size() - 1; i++) {
            if (dec[i] > dec[i + 1]) {
                // dec[i] = dec[i + 1];
                int j = i + 1;
                int k = i - 1;
                while (j < dec.size())
                    dec[j++] = 9;
                while (i > 0 && dec[i] == dec[i - 1])
                    dec[i--] = 9;
                if ((i > 0 && dec[i] > dec[i - 1]) || i == 0)
                    dec[i] = dec[i] - 1;
                break;
            }
        }
        int sum = 0;
        for (int i = 0; i < dec.size(); i++) {
            sum += dec[i] * ten(dec.size() - i - 1);
        }
        return sum;
    }
};
// @lc code=end
