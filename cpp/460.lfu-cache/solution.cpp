// Created by zwyyy456 at 2023/05/04 19:13
// https://leetcode.com/problems/lfu-cache/

/*
460. LFU Cache (Hard)
Design and implement a data structure for a [Least Frequently Used
(LFU)](https://en.wikipedia.org/wiki/Least_frequently_used) cache.

Implement the `LFUCache` class:

- `LFUCache(int capacity)` Initializes the object with the `capacity` of the data structure.
- `int get(int key)` Gets the value of the `key` if the `key` exists in the cache. Otherwise, returns
`-1`.
- `void put(int key, int value)` Update the value of the `key` if present, or inserts the `key` if
not already present. When the cache reaches its `capacity`, it should invalidate and remove the
**least frequently used** key before inserting a new item. For this problem, when there is a **tie**
(i.e., two or more keys with the same frequency), the **least recently used** `key` would be
invalidated.

To determine the least frequently used key, a **use counter** is maintained for each key in the
cache. The key with the smallest **use counter** is the least frequently used key.

When a key is first inserted into the cache, its **use counter** is set to `1` (due to the `put`
operation). The **use counter** for a key in the cache is incremented either a `get` or `put`
operation is called on it.

The functions `get` and `put` must each run in `O(1)` average time complexity.

**Example 1:**

```
Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3

```

**Constraints:**

- `1 <= capacity <= 10⁴`
- `0 <= key <= 10⁵`
- `0 <= value <= 10⁹`
- At most `2 * 10⁵` calls will be made to `get` and `put`.

*/

#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
struct Node {
    Node *next_;
    Node *prev_;
    int val_;
    int idx_;
    Node(int val) :
        next_(nullptr), prev_(nullptr), val_(val), idx_(0) {
    }
};
struct Mlist {
    Node *vhead_;
    Node *vtail_;
    int size_;
    Mlist() :
        vhead_(new Node(0)), vtail_(new Node(0)), size_(2) {
        vhead_->next_ = vtail_;
        vtail_->prev_ = vhead_;
    }
    void Insert(Node *to_ins) {
        Node *tmp = vtail_->prev_;
        tmp->next_ = to_ins;
        to_ins->prev_ = tmp;
        to_ins->next_ = vtail_;
        vtail_->prev_ = to_ins;
        ++size_;
    }
    void Delete(Node *to_del) {
        to_del->prev_->next_ = to_del->next_;
        to_del->next_->prev_ = to_del->prev_;
        delete to_del;
        to_del = nullptr;
        --size_;
    }
    void Delete() {
        Delete(vhead_->next_);
    }
    ~Mlist() {
        delete vhead_;
        delete vtail_;
    }
};
class LFUCache {
  public:
    LFUCache(int capacity) :
        cap_(capacity), size_(0), min_freq_(0) {
    }

    int get(int key) {
        if (id_freq.find(key) == id_freq.end()) {
            return -1;
        }
        auto freq = id_freq[key]++;
        auto plist = freq_list[freq];
        auto pnode = id_p[key];
        int val = pnode->val_;
        plist->Delete(pnode); // pnode 已经被 delete 了
        if (plist->size_ == 2) {
            if (freq == min_freq_) {
                min_freq_++;
            }
            freq_list.erase(freq);
        }
        auto new_node = new Node(val);
        new_node->idx_ = key; // 创建出来这个新的 node
        ++freq;
        (freq_list[freq])->Insert(new_node);
        id_p[key] = new_node;
    }

    void put(int key, int value) {
        if (id_freq.find(key) != id_freq.end()) {
            get(key);
            id_p[key]->val_ = value;
        } else {
            auto new_node = new Node(value);
            new_node->idx_ = key;
            if (size_ < cap_) {
                // 直接插入即可
                freq_list[id_freq[key]]->Insert(new_node);
                ++size_;
                min_freq_ = 1;
                id_freq[key]++;
            } else {
                // 先删除，再插入
                int del_id = freq_list[min_freq_]->vtail_->prev_->idx_;
                freq_list[min_freq_]->Delete();
                if (freq_list[min_freq_]->size_ == 2) {
                    id_freq.erase(del_id);
                    freq_list.erase(min_freq_);
                }
                min_freq_ = 1;
                freq_list[min_freq_]->Insert(new_node);
                id_freq[key]++;
            }
            id_p[key] = new_node;
        }
    }

  private:
    unordered_map<int, int> id_freq;
    unordered_map<int, Node *> id_p;
    unordered_map<int, Mlist *> freq_list;
    int size_;
    int cap_;
    int min_freq_;
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    LFUCache *obj;

    const unordered_map<string, function<void()>> methods = {
        {"LFUCache", [&]() {
             int capacity;
             LeetCodeIO::scan(cin, capacity);
             cin.ignore();
             obj = new LFUCache(capacity);
             out_stream << "null,";
         }},
        {"get", [&]() {
             int key;
             LeetCodeIO::scan(cin, key);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->get(key));
             out_stream << ',';
         }},
        {"put", [&]() {
             int key;
             LeetCodeIO::scan(cin, key);
             cin.ignore();
             int value;
             LeetCodeIO::scan(cin, value);
             cin.ignore();
             obj->put(key, value);
             out_stream << "null,";
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
