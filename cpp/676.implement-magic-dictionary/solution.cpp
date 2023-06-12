// Created by zwyyy456 at 2023/05/29 10:20
// https://leetcode.com/problems/implement-magic-dictionary/

/*
676. Implement Magic Dictionary (Medium)
Design a data structure that is initialized with a list of **different** words. Provided a string,
you should determine if you can change exactly one character in this string to match any word in the
data structure.

Implement the `MagicDictionary` class:

- `MagicDictionary()` Initializes the object.
- `void buildDict(String[] dictionary)` Sets the data structure with an array of distinct strings
`dictionary`.
- `bool search(String searchWord)` Returns `true` if you can change **exactly one character** in
`searchWord` to match any string in the data structure, otherwise returns `false`.

**Example 1:**

```
Input
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
Output
[null, null, false, true, false, false]

Explanation
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict(["hello", "leetcode"]);
magicDictionary.search("hello"); // return False
magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we
return True
magicDictionary.search("hell"); // return False
magicDictionary.search("leetcoded"); // return False

```

**Constraints:**

- `1 <= dictionary.length <= 100`
- `1 <= dictionary[i].length <= 100`
- `dictionary[i]` consists of only lower-case English letters.
- All the strings in `dictionary` are **distinct**.
- `1 <= searchWord.length <= 100`
- `searchWord` consists of only lower-case English letters.
- `buildDict` will be called only once before `search`.
- At most `100` calls will be made to `search`.

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class MagicDictionary {
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        
    }
    
    bool search(string searchWord) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names; LeetCodeIO::scan(cin, method_names);

	MagicDictionary *obj;

	const unordered_map<string, function<void()>> methods = {
		{ "MagicDictionary", [&]() {
			cin.ignore();
			obj = new MagicDictionary();
			out_stream << "null,";
		} },
		{ "buildDict", [&]() {
			vector<string> dictionary; LeetCodeIO::scan(cin, dictionary); cin.ignore();
			obj->buildDict(dictionary);
			out_stream << "null,";
		} },
		{ "search", [&]() {
			string searchWord; LeetCodeIO::scan(cin, searchWord); cin.ignore();
			LeetCodeIO::print(out_stream, obj->search(searchWord)); out_stream << ',';
		} },
	};
	out_stream << '[';
	for (auto &&method_name : method_names) {
		cin.ignore(2);
		methods.at(method_name)();
	}
	cin.ignore();
	out_stream.seekp(-1, ios_base::end); out_stream << ']';

	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
