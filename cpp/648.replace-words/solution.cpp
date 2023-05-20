// Created by zwyyy456 at 2023/05/10 15:46
// https://leetcode.com/problems/replace-words/

/*
648. Replace Words (Medium)
In English, we have a concept called **root**, which can be followed by some other word to form
another longer word - let's call this word **successor**. For example, when the **root** `"an"` is
followed by the **successor** word `"other"`, we can form a new word `"another"`.

Given a `dictionary` consisting of many **roots** and a `sentence` consisting of words separated by
spaces, replace all the **successors** in the sentence with the **root** forming it. If a
**successor** can be replaced by more than one **root**, replace it with the **root** that has **the
shortest length**.

Return the `sentence` after the replacement.

**Example 1:**

```
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

```

**Example 2:**

```
Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"

```

**Constraints:**

- `1 <= dictionary.length <= 1000`
- `1 <= dictionary[i].length <= 100`
- `dictionary[i]` consists of only lower-case letters.
- `1 <= sentence.length <= 10⁶`
- `sentence` consists of only lower-case letters and spaces.
- The number of words in `sentence` is in the range `[1, 1000]`
- The length of each word in `sentence` is in the range `[1, 1000]`
- Every two consecutive words in `sentence` will be separated by exactly one space.
- `sentence` does not have leading or trailing spaces.

*/

#include <bits/stdc++.h>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
    	// 哈希表应该能做
    	unordered_set<string> dict(dictionary.begin(), dictionary.end());
    	vector<string> words;
    	int l = 0, r = 0;
    	for (l = 0, r = 0; r < sentence.size(); ++r) {
    		if (r == ' ') {
    			words.push_back(sentence.substr(l, r - l));
    			l = r + 1;
    		}
    	}
    	words.push_back(sentence.substr(l, r - l));
    	for (int i = 0; i < words.size(); ++i) {
    		for (int j = 0; j < words[i].size(); ++j) {
    			if (dict.find(words[i].substr(0, j + 1)) != dict.end()) {
    				words[i] = words[i].substr(0, j + 1);
    				break;
    			}
    		}
    	} 
    	string res;
    	for (int i = 0; i < words.size(); ++i) {
    		res += words[i];
    		res.push_back(' ');
    	}
    	res.pop_back();
    	return res;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> dictionary; LeetCodeIO::scan(cin, dictionary);
	string sentence; LeetCodeIO::scan(cin, sentence);

	Solution *obj = new Solution();

	auto res = obj->replaceWords(dictionary, sentence);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
