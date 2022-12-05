/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
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
    vector<int> findSubstring(string s, vector<string> &words) {

        unordered_map<string, int> mp;
        int word_len = words[0].size();
        int cnt = 0;
        vector<int> res;
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]]++;
            cnt++;
        }
        // i : [0, word_len - 1], 对每一个i组成的单词序列，都单独使用滑动窗口法判断
        for (int i = 0; i < word_len; i++) {
            int l = i;
            unordered_map<string, int> mp_tmp = mp;
            // unordered_map<string, int> mp_tmp2 = mp;
            for (int r = i; r < s.size() - word_len; r += word_len) {
                string tmp = s.substr(r, word_len);
                // 单词在words中
                if (mp_tmp.find(tmp) != mp_tmp.end()) {
                    mp_tmp[tmp]--;
                    // 说明出现了超过words里单词的数量
                    if (mp_tmp[tmp] == 0)
                        mp_tmp.erase(tmp);
                    if (mp_tmp.empty()) {
                        res.push_back(l); // 说明找到了目标
                        // mp_tmp = mp; // map变成新的
                        mp_tmp[s.substr(l, word_len)]++;
                        l += word_len;
                    }

                } else {
                    if (mp.find(tmp) == mp.end()) { // 说明这个单词不在words里面
                        l = r + word_len;
                        mp_tmp = mp;
                    } else {
                        string str_l = s.substr(l, word_len);
                        while (str_l != tmp) {
                            mp_tmp[str_l]++;
                            l += word_len;
                            str_l = s.substr(l, word_len);
                        }
                        l += word_len;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end
