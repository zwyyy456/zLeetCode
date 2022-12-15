/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>
using std::string;
using std::unordered_map;
using std::vector;
class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;

        for (char &c : p)
            mp[c]++;
        vector<int> res;
        unordered_map<char, int> tmp = mp;
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (tmp.find(s[r]) != tmp.end()) {
                tmp[s[r]]--;
                if (tmp[s[r]] == 0) {
                    tmp.erase(s[r]);
                    if (tmp.empty()) {
                        res.push_back(l);
                        tmp[s[l++]]++;
                    }
                }
            } else {
                if (mp.find(s[r]) != mp.end()) {
                    while (s[l] != s[r]) {
                        l++;
                        mp[s[l]]++;
                    }
                    l++;
                } else { // s[r]不在p中
                    l = r + 1;
                    tmp = mp;
                }
            }
        }
        return res;
    }
};
// @lc code=end
