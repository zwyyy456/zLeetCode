// Created by zwyyy456 at 2023/05/14 15:04
// https://leetcode.com/problems/repeated-dna-sequences/

/*
187. Repeated DNA Sequences (Medium)
The **DNA sequence** is composed of a series of nucleotides abbreviated as `'A'`, `'C'`, `'G'`, and
`'T'`.

- For example, `"ACGAATTCCG"` is a **DNA sequence**.

When studying **DNA**, it is useful to identify repeated sequences within the DNA.

Given a string `s` that represents a **DNA sequence**, return all the **`10`-letter-long** sequences
(substrings) that occur more than once in a DNA molecule. You may return the answer in **any
order**.

**Example 1:**

```
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

```

**Example 2:**

```
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]

```

**Constraints:**

- `1 <= s.length <= 10⁵`
- `s[i]` is either `'A'`, `'C'`, `'G'`, or `'T'`.

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
       	vector<string> res;
       	if (s.size() <= 10) {
       		return res;
       	}
       	unordered_map<string, int> strs;
       	for (int i = 0; i + 10 <= s.size(); ++i) {
       		string str = s.substr(i, i + 10);
       		++strs[str];
       	} 
       	for (auto &str : strs) {
       		if (str.second > 1) {
       			res.push_back(str.first);
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

	Solution *obj = new Solution();

	auto res = obj->findRepeatedDnaSequences(s);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
