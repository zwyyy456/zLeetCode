/*
 * @lc app=leetcode id=1812 lang=cpp
 *
 * [1812] Determine Color of a Chessboard Square
 */

// @lc code=start
#include <string>
using std::string;
class Solution {
  public:
    bool squareIsWhite(string coordinates) {
        if ((coordinates[0] - 'a' + 1 - coordinates[1]) % 2 == 0)
            return false;
        else
            return true;
    }
};
// @lc code=end
