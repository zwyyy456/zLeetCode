/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
#include <string>
#include <vector>
using std::vector;
using std::string;
class Solution {
    private:
    vector<string> res;
    vector<string> path;
    void track_back(string s, int index) {
        if (path.size() == 3) {
            if (check_ip(s) == true)
                
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        
        if (s.size() < 4 || s.size() > 12)
            return res;
    }
};
// @lc code=end

