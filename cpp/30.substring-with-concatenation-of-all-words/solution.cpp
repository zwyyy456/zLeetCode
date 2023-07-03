// Created by zwyyy456 at 2023/06/13 10:55
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

/*
30. Substring with Concatenation of All Words (Hard)
You are given a string `s` and an array of strings `words`. All the strings of `words` are of **the
same length**.

A **concatenated substring** in `s` is a substring that contains all the strings of any permutation
of `words` concatenated.

- For example, if `words = ["ab","cd","ef"]`, then `"abcdef"`, `"abefcd"`, `"cdabef"`, `"cdefab"`,
`"efabcd"`, and `"efcdab"` are all concatenated strings. `"acdbef"` is not a concatenated substring
because it is not the concatenation of any permutation of `words`.

Return the starting indices of all the concatenated substrings in  `s`. You can return the answer in
**any order**.

**Example 1:**

```
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Since words.length == 2 and words[i].length == 3, the concatenated substring has to be
of length 6.
The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a
permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a
permutation of words.
The output order does not matter. Returning [9,0] is fine too.

```

**Example 2:**

```
Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Explanation: Since words.length == 4 and words[i].length == 4, the concatenated substring has to be
of length 16.
There is no substring of length 16 is s that is equal to the concatenation of any permutation of
words.
We return an empty array.

```

**Example 3:**

```
Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
Explanation: Since words.length == 3 and words[i].length == 3, the concatenated substring has to be
of length 9.
The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"] which is
a permutation of words.
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"] which is
a permutation of words.
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"] which is
a permutation of words.

```

**Constraints:**

- `1 <= s.length <= 10⁴`
- `1 <= words.length <= 5000`
- `1 <= words[i].length <= 30`
- `s` and `words[i]` consist of lowercase English letters.

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
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

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s; LeetCodeIO::scan(cin, s);
	vector<string> words; LeetCodeIO::scan(cin, words);

	Solution *obj = new Solution();

	auto res = obj->findSubstring(s, words);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}

