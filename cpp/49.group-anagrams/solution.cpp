// Created by zwyyy456 at 2023/04/22 16:18
// https://leetcode.com/problems/group-anagrams/

/*
49. Group Anagrams (Medium)
Given an array of strings `strs`, group **the anagrams** together. You can return the answer in
**any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

**Example 1:**

```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

```

**Example 2:**

```
Input: strs = [""]
Output: [[""]]

```

**Example 3:**

```
Input: strs = ["a"]
Output: [["a"]]

```

**Constraints:**

- `1 <= strs.length <= 10⁴`
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lowercase English letters.

*/

#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	auto SortStr(string &str) -> string {
		vector<char> tmp(str.begin(), str.end());
		sort(tmp.begin(), tmp.end());
		string res(tmp.begin(), tmp.end());
		return res;
	}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       	unordered_map<string, vector<string>> pairs;
       	for (auto &str : strs) {
       		auto tmp = SortStr(str);
       		// if (pairs.find(tmp) == pairs.end()) {
       			pairs[tmp].emplace_back(str);
       		// }
       	}
       	vector<vector<string>> res;
       	for (auto &pair_str : pairs) {
       		res.emplace_back(pair_str.second);
       	}
       	return res;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> strs; LeetCodeIO::scan(cin, strs);

	Solution *obj = new Solution();

	auto res = obj->groupAnagrams(strs);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
