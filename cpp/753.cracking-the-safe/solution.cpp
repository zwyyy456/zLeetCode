/*
 * @lc app=leetcode id=753 lang=cpp
 *
 * [753] Cracking the Safe
 */

// @lc code=start
#include <math.h>
#include <string>
#include <unordered_set>
using std::string;
using std::unordered_set;
class Solution {
  public:
    string ans;
    void dfs(string &res, unordered_set<string> &ss, int k, int n, int target_num) { // k表示密码总的组合数
        // if (res.size() >= n) { 
        //     if (ss.find(res.substr(res.size() - n, n)) != ss.end()) // 末尾n位已经在ss中
        //         return;
        //     else {
        //         ss.insert(res.substr(res.size() - n, n));
        //         if (ss.size() == target_num) {
        //             ans = res;
        //             return;
        //         }
        //     }
        // }
        int flag_ss = 0; // 标志ss是否插入了新的元素

        for (int i = 0; i < k; i++) {
            res.push_back(i + '0');
            if (res.size() >= n) {
                if (ss.find(res.substr(res.size() - n, n)) != ss.end())
                    return;
                else {
                    ss.insert(res.substr(res.size() - n, n));
                    flag_ss = 1;
                    if (ss.size() == target_num) {
                        ans = res;
                        break;
                    }
                }
                dfs(res, ss, k, n, target_num);
                if (flag_ss = 1)
                    ss.erase(res.substr(res.size() - n, n));
                res.pop_back();
                    
            } else {
                dfs(res, ss, k, n, target_num);
                res.pop_back();
            }
        }
        return;
    }
    string crackSafe(int n, int k) {
        unordered_set<string> ss;
        string res(n, '0');
        ss.insert(res);
        int target_num = pow(k, n);
        dfs(res, ss, k, n, target_num);
        return ans;
    }
};
// @lc code=end
