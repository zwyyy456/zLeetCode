/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
  public:
    vector<string> res;
    string ip;
    bool check_ip(string &s) {
        if (s.size() > 3)
            return false;
        if (s[0] == '0') {
            if (s.size() == 1)
                return true;
            else
                return false;
        } else {
            int num = stoi(s);
            if (num > 255)
                return false;
            else
                return true;
        }
    }
    void backtrack(string &s, int index, string ip, int cnt) {
        if (index >= s.size()) {
            if (cnt == 4) {
                ip.pop_back();
                res.push_back(ip);
                return;
            }
        }
        for (int i = index; i < s.size(); i++) {
            string tmp = s.substr(index, i - index + 1);
            if (check_ip(tmp)) {
                backtrack(s, i + 1, ip + tmp + ".", cnt + 1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string ip;
        backtrack(s, 0, ip, 0);
        return res;
    }
};
// @lc code=end
