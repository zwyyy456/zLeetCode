/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
#include <stack>
#include <string>
#include <vector>
using std::stack;
using std::string;
using std::vector;
class Solution {
  public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        int arr[26] = {0};
        int arr_bool[26] = {0};
        int len = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            arr[s[i] - 'a']++;
            arr_bool[s[i] - 'a'] = 1;
        }
        for (int i = 0; i < s.size(); i++) {
            len++;
            arr[s[i] - 'a']--;
            if (arr_bool[s[i] - 'a'] != 0) {
                st.push(s[i]);
                arr_bool[s[i] - 'a'] = 0;
            }
            if (arr[s[i] - 'a'] == 0)
                st.pop();
            if (st.empty()) {
                res.push_back(len);
                len = 0;
            }
        }
        return res;
    }
};
// @lc code=end
