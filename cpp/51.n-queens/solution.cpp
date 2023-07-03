/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
#include <string>
#include <vector>
using std::vector, std::string;
class Solution {
  private:
    int row_col[17] = {0};
    int row_plus_col[17] = {0};
    int row_arr[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9};
    int col_arr[9] = {0};
    // int col = 0;
    string path = ".........";
    vector<string> row_str;
    vector<vector<string>> res;
    void track_back(int n, int index) {
        if (index >= n) {
            res.push_back(row_str);
            return;
        }
        for (int i = 0; i < n; i++) { // i表示在第几列，index表示在第几行
            if (col_arr[i] != 0 || row_col[i - index + 8] != 0 || row_plus_col[i + index] != 0)
                continue;
            col_arr[i] = 1;
            row_col[i - index + 8] = 1;
            row_plus_col[i + index] = 1;
            string path_tmp = path.substr(0, n);
            path_tmp[i] = 'Q';
            row_str.push_back(path_tmp);
            track_back(n, index + 1);
            col_arr[i] = 0;
            row_col[i - index + 8] = 0;
            row_plus_col[i + index] = 0;
            path_tmp[i] = '.';
            row_str.pop_back();
            
        }
        return;
    }

  public:
    vector<vector<string>> solveNQueens(int n) {
        track_back(n, 0);
        return res;
    }
};
// @lc code=end
