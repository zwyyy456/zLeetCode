// Created by zwyyy456 at 2023/04/29 18:15
// https://leetcode.com/problems/remove-letter-to-equalize-frequency/

/*
2423. Remove Letter To Equalize Frequency (Easy)
You are given a **0-indexed** string `word`, consisting of lowercase English letters. You need to
select **one** index and **remove** the letter at that index from `word` so that the **frequency**
of every letter present in `word` is equal.

Return `true` if it is possible to remove one letter so that the frequency of all letters in  `word`
are equal, and  `false` otherwise.

**Note:**

- The **frequency** of a letter `x` is the number of times it occurs in the string.
- You **must** remove exactly one letter and cannot chose to do nothing.

**Example 1:**

```
Input: word = "abcc"
Output: true
Explanation: Select index 3 and delete it: word becomes "abc" and each character has a frequency of
1.

```

**Example 2:**

```
Input: word = "aazz"
Output: false
Explanation: We must delete a character, so either the frequency of "a" is 1 and the frequency of
"z" is 2, or vice versa. It is impossible to make all present letters have equal frequency.

```

**Constraints:**

- `2 <= word.length <= 100`
- `word` consists of lowercase English letters only.

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    bool equalFrequency(string word) {
        int arr[26] = {0};
        int flag = 0;
        int idx = 0;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            arr[c - 'a']++;
        }
        unordered_map<int, int> cnt;
        int min_num = 101, max_num = 0;
        for (auto num : arr) {
            if (num != 0) {
                ++cnt[num];
                min_num = min(num, min_num);
                max_num = max(num, max_num);
            }
        }
        if (cnt.size() == 2) {
            return cnt[max_num] == 1 || cnt[min_num] == 1;
        }
        return cnt.size() == 1 && max_num == 1;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string word;
    LeetCodeIO::scan(cin, word);

    Solution *obj = new Solution();

    auto res = obj->equalFrequency(word);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
