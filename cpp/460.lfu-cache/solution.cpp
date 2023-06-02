// Created by zwyyy456 at 2023/06/02 15:50
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

#include <arm/types.h>
#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

struct Node {
    Node() {
    }
    Node(int val, int key) :
        val_(val), key_(key), next_(nullptr), pre_(nullptr) {
    }
    int val_;
    int freq_;
    Node *next_;
    Node *pre_;
    int key_;
};
struct List {
    Node *vhead_;  // 虚拟头结点
    Node *vtail_;  // 虚拟尾结点
    int size_ = 0; // 链表中有效结点的数量
    List() :
        vhead_(new Node()), vtail_(new Node()) {
        vhead_->next_ = vtail_;
        vtail_->pre_ = vhead_;
        vhead_->pre_ = nullptr;
        vtail_->next_ = nullptr;
    }
    ~List() {
        delete vtail_;
        delete vhead_;
        vhead_ = nullptr;
        vtail_ = nullptr;
    }
    void Insert(Node *node) {
        // 双向链表的插入, node 表示待插入结点，插入作为双向链表的尾结点
        node->pre_ = vtail_->pre_;
        vtail_->pre_->next_ = node;
        vtail_->pre_ = node;
        node->next_ = vtail_;
        ++size_;
    }
    void Delete(Node *node) {
        // node 指向待删除结点
        node->next_->pre_ = node->pre_;
        node->pre_->next_ = node->next_;
        --size_;
    }
    bool Empty() {
        return size_ <= 0;
    }
};
class LFUCache {
  public:
    LFUCache(int capacity) :
        cap_(capacity), min_freq_(0), cnt_(0) {
    }

    int get(int key) {
        if (hash_.find(key) == hash_.end()) {
            return -1;
        }
        Node *node = hash_[key];
        int freq = node->freq_;
        // 要更新频率，因此要从原先的频率链表上删除该结点
        freqs_[freq]->Delete(node);
        if (freqs_[freq]->Empty()) {
            // 删除该链表，频率哈希表中移除该频率
            delete freqs_[freq];
            freqs_.erase(freq);
            if (min_freq_ == freq) {
                // 则需要更新最小频率
                min_freq_ = freq + 1;
            }
        }
        // 更新频率
        ++node->freq_;
        freq = node->freq_;
        if (freqs_.find(freq) == freqs_.end()) {
            freqs_[freq] = new List();
        }
        freqs_[freq]->Insert(node);
        return node->val_;
    }

    void put(int key, int value) {
        // key 已经在缓存中了
        if (hash_.find(key) != hash_.end()) {
            get(key);
            hash_[key]->val_ = value;
            return;
        }
        /* key 不在缓存中 */
        // 缓存已满
        if (cnt_ == cap_) {
            // 删除 min_freq_ 链表对应的头结点
            List *lst = freqs_[min_freq_];
            Node *to_del = lst->vhead_->next_;
            lst->Delete(to_del);
            hash_.erase(to_del->key_);
            delete to_del;
            to_del = nullptr;
            // 如果 lst 变为空
            if (lst->Empty()) {
                delete lst;
                lst = nullptr;
                freqs_.erase(min_freq_);
            }
            // 现在执行插入
            Node *node = new Node(value, key);
            node->freq_ = 1;
            min_freq_ = 1;
            if (freqs_.find(node->freq_) == freqs_.end()) {
                freqs_[node->freq_] = new List();
            }
            freqs_[node->freq_]->Insert(node);
            hash_[key] = node;
        } else {
            // 现在执行插入
            Node *node = new Node(value, key);
            node->freq_ = 1;
            min_freq_ = 1;
            if (freqs_.find(node->freq_) == freqs_.end()) {
                freqs_[node->freq_] = new List();
            }
            freqs_[node->freq_]->Insert(node);
            hash_[key] = node;
            ++cnt_;
        }
    }

  private:
    unordered_map<int, Node *> hash_;
    unordered_map<int, List *> freqs_;
    int min_freq_;
    int cnt_;
    int cap_;
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
