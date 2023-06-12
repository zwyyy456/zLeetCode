// Created by zwyyy456 at 2023/06/06 16:05
// https://leetcode.com/problems/design-skiplist/

/*
1206. Design Skiplist (Hard)
Design a **Skiplist** without using any built-in libraries.

A **skiplist** is a data structure that takes `O(log(n))` time to add, erase and search. Comparing
with treap and red-black tree which has the same function and performance, the code length of
Skiplist can be comparatively short and the idea behind Skiplists is just simple linked lists.

For example, we have a Skiplist containing `[30,40,50,60,70,90]` and we want to add `80` and `45`
into it. The Skiplist works this way:

![](https://assets.leetcode.com/uploads/2019/09/27/1506_skiplist.gif)

Artyom Kalinin \[CC BY-SA 3.0\], via [Wikimedia
Commons](https://commons.wikimedia.org/wiki/File:Skip_list_add_element-en.gif "Artyom Kalinin [CC BY-
SA 3.0 (https://creativecommons.org/licenses/by-sa/3.0)], via Wikimedia Commons")

You can see there are many layers in the Skiplist. Each layer is a sorted linked list. With the help
of the top layers, add, erase and search can be faster than `O(n)`. It can be proven that the
average time complexity for each operation is `O(log(n))` and space complexity is `O(n)`.

See more about Skiplist:
[https://en.wikipedia.org/wiki/Skip\_list](https://en.wikipedia.org/wiki/Skip_list)

Implement the `Skiplist` class:

- `Skiplist()` Initializes the object of the skiplist.
- `bool search(int target)` Returns `true` if the integer `target` exists in the Skiplist or `false`
otherwise.
- `void add(int num)` Inserts the value `num` into the SkipList.
- `bool erase(int num)` Removes the value `num` from the Skiplist and returns `true`. If `num` does
not exist in the Skiplist, do nothing and return `false`. If there exist multiple `num` values,
removing any one of them is fine.

Note that duplicates may exist in the Skiplist, your code needs to handle this situation.

**Example 1:**

```
Input
["Skiplist", "add", "add", "add", "search", "add", "search", "erase", "erase", "search"]
[[], [1], [2], [3], [0], [4], [1], [0], [1], [1]]
Output
[null, null, null, null, false, null, true, false, true, false]

Explanation
Skiplist skiplist = new Skiplist();
skiplist.add(1);
skiplist.add(2);
skiplist.add(3);
skiplist.search(0); // return False
skiplist.add(4);
skiplist.search(1); // return True
skiplist.erase(0);  // return False, 0 is not in skiplist.
skiplist.erase(1);  // return True
skiplist.search(1); // return False, 1 has already been erased.
```

**Constraints:**

- `0 <= num, target <= 2 * 10⁴`
- At most `5 * 10⁴` calls will be made to `search`, `add`, and `erase`.

*/

#include <bits/stdc++.h>
#include <vector>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
const int klevel = 8;
struct Node {
    int val_;
    vector<Node *> next_; // next[i] 表示当前结点在第 i 层的 next，i 从 0 开始

    Node(int val) :
        val_(val), next_{klevel, nullptr} {
    }
};
class Skiplist {
  public:
    Skiplist() :
        head(new Node(-1)), pre_(klevel) {
        // 初始化为 -1，表示结点不存在
    }
    void Find(int target, vector<Node *> &pre) {
        // 辅助函数，找到每一层 pre[i] 小于 target 的最大的 i
        // 从头结点开始遍历每一层
        for (int i = 0; i < klevel; ++i) {
            pre[i] = nullptr;
        }
        auto *ptr = head;
        for (int i = klevel - 1; i >= 0; --i) { // 从上层开始往下层找，这里从下往上是不是也可以？
            // 如果当前层 i 对应结点的 next 不为空，且它的值小于 target，则 ptr 往前走指向这一层 ptr 的 next
            while ((ptr->next_[i] != nullptr) && ptr->next_[i]->val_ < target) {
                ptr = ptr->next_[i];
            }
            pre[i] = ptr;
        }
    }
    bool search(int target) {
        Find(target, pre_);
        auto *ptr = (pre_[0]->next_)[0];
        return ptr != nullptr && ptr->val_ == target;
    }

    void add(int num) {
        Find(num, pre_);
        auto *ptr = new Node(num);
        for (int i = 0; i < klevel; ++i) {
            ptr->next_[i] = pre_[i]->next_[i]; // 其实就是链表的插入操作
            pre_[i]->next_[i] = ptr;
            if (random() % 2 == 1) {
                break;
            }
        }
    }

    bool erase(int num) {
        if (!search(num)) {
            return false;
        }
        auto *ptr = pre_[0]->next_[0];
        for (int i = 0; i < klevel && pre_[i]->next_[i] == ptr; ++i) {
            pre_[i]->next_[i] = ptr->next_[i];
        }
        delete ptr;
        return true;
    }

  private:
    Node *head; // 跳表头结点
    vector<Node *> pre_;
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    Skiplist *obj;

    const unordered_map<string, function<void()>> methods = {
        {"Skiplist", [&]() {
             cin.ignore();
             obj = new Skiplist();
             out_stream << "null,";
         }},
        {"search", [&]() {
             int target;
             LeetCodeIO::scan(cin, target);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->search(target));
             out_stream << ',';
         }},
        {"add", [&]() {
             int num;
             LeetCodeIO::scan(cin, num);
             cin.ignore();
             obj->add(num);
             out_stream << "null,";
         }},
        {"erase", [&]() {
             int num;
             LeetCodeIO::scan(cin, num);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->erase(num));
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
