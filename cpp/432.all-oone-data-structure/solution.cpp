// Created by zwyyy456 at 2023/05/05 10:08
// https://leetcode.com/problems/all-oone-data-structure/

/*
432. All O`one Data Structure (Hard)
Design a data structure to store the strings' count with the ability to return the strings with
minimum and maximum counts.

Implement the `AllOne` class:

- `AllOne()` Initializes the object of the data structure.
- `inc(String key)` Increments the count of the string `key` by `1`. If `key` does not exist in the
data structure, insert it with count `1`.
- `dec(String key)` Decrements the count of the string `key` by `1`. If the count of `key` is `0`
after the decrement, remove it from the data structure. It is guaranteed that `key` exists in the
data structure before the decrement.
- `getMaxKey()` Returns one of the keys with the maximal count. If no element exists, return an empty
string `""`.
- `getMinKey()` Returns one of the keys with the minimum count. If no element exists, return an empty
string `""`.

**Note** that each function must run in `O(1)` average time complexity.

**Example 1:**

```
Input
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
Output
[null, null, null, "hello", "hello", null, "hello", "leet"]

Explanation
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "hello"
allOne.inc("leet");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "leet"

```

**Constraints:**

- `1 <= key.length <= 10`
- `key` consists of lowercase English letters.
- It is guaranteed that for each call to `dec`, `key` is existing in the data structure.
- At most `5 * 10⁴` calls will be made to `inc`, `dec`, `getMaxKey`, and `getMinKey`.

*/

#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class AllOne {
  public:
    AllOne() :
        min_cnt(100001), max_cnt(0), min_pre(100001) {
    }

    void inc(string key) {
        if (key_num.find(key) == key_num.end()) {
            // 说明不存在该字符串
            key_num[key] = 1;
            num_keys[1].insert(key);
            min_pre = min_cnt;
            min_cnt = 1;
            max_cnt = max(1, max_cnt);
        } else {
            // 说明存在该字符串
            int cnt = key_num[key]++;
            num_keys[cnt].erase(key);
            if (num_keys[cnt].empty() && min_cnt == cnt) {
                ++min_cnt;
            }
            num_keys[cnt + 1].insert(key);
            max_cnt = max(max_cnt, cnt + 1);
        }
    }

    void dec(string key) {
        int cnt = key_num[key]--;
        if (key_num[key] == 0) {
            key_num.erase(key);
        }
    }

    string getMaxKey() {
    }

    string getMinKey() {
    }

  private:
    unordered_map<string, int> key_num;
    unordered_map<int, unordered_set<string>> num_keys;
    int min_cnt;
    int min_pre;
    int max_cnt;
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    AllOne *obj;

    const unordered_map<string, function<void()>> methods = {
        {"AllOne", [&]() {
             cin.ignore();
             obj = new AllOne();
             out_stream << "null,";
         }},
        {"inc", [&]() {
             string key;
             LeetCodeIO::scan(cin, key);
             cin.ignore();
             obj->inc(key);
             out_stream << "null,";
         }},
        {"dec", [&]() {
             string key;
             LeetCodeIO::scan(cin, key);
             cin.ignore();
             obj->dec(key);
             out_stream << "null,";
         }},
        {"getMaxKey", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->getMaxKey());
             out_stream << ',';
         }},
        {"getMinKey", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->getMinKey());
             out_stream << ',';
         }},
    };
    out_stream << '[';
    for (auto &&method_name : method_names) {
        cin.ignore(2);
        methods.at(method_name)();
    }
    cin.ignore();
    out_stream.seekp(-1, ios_base::end);
    out_stream << ']';

    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
