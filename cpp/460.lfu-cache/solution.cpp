// Created by zwyyy456 at 2023/05/31 14:19
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

#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
struct Node {
    int val_;
    int freq_;
    Node *next_;
    Node *pre_;
    int key_;
};
struct List {
    List() :
        vhead_(new Node()), vtail_(new Node()) {
        vhead_->next_ = vtail_;
        vhead_->pre_ = nullptr;
        vtail_->pre_ = vhead_;
        vtail_->next_ = nullptr;
    }
    ~List() {
        delete vhead_;
        delete vtail_;
        vhead_ = nullptr;
        vtail_ = nullptr;
    }
    Node *vhead_;
    Node *vtail_;
    int size_;
};
class LFUCache {
  public:
    LFUCache(int capacity) :
        cap_(capacity) {
    }

    int get(int key) {
        if (map_.find(key) == map_.end()) {
            return -1;
        }
        Node *cur = map_[key];
        int freq = cur->freq_;
        int val = cur->val_;
        // 删除当前 freq 的对应结点
        cur->next_->pre_ = cur->pre_;
        cur->pre_->next_ = cur->next_;
        // delete cur;
        // cur = nullptr;
        // 如果删除后 list 变为空
        if (freqs_[freq]->vhead_->next_ == freqs_[freq]->vtail_) {
            delete freqs_[freq];
            // 如果最小频率就是 freq，更新最小频率
            if (min_freq_ == freq) {
                min_freq_ = freq + 1;
            }
            // 删除该 freq
            freqs_.erase(freq);
        }
        // 删除之后，在 freq + 1 处插入新的结点
        ++freq;
        // 如果 freq 不存在
        if (freqs_.find(freq) == freqs_.end()) {
            freqs_[freq] = new List();
        }
        List *lst = freqs_[freq];
        // 从尾部插入
        ++cur->freq_;
        cur->pre_ = lst->vtail_->pre_;
        lst->vtail_->pre_->next_ = cur;
        cur->next_ = lst->vtail_;
        lst->vtail_->pre_ = cur;
        return val;
    }

    void put(int key, int value) {
        if (map_.find(key) != map_.end()) {
            get(key);
            map_[key]->val_ = value;
            return;
        }
        // 说明找得到键，并且容量已经满了
        if (cnt_ == cap_) {
            // 要先删除结点
            List *lst = freqs_[min_freq_];
            Node *head = lst->vhead_->next_;
            head->next_->pre_ = head->pre_;
            head->pre_->next_ = head->next_;
            map_.erase(head->key_);
            delete head;
            // 因为要重新插入 key-value，min_freq_ 一定会变成 1
            if (lst->vhead_->next_ == lst->vtail_ && lst->vtail_->pre_ == lst->vhead_) {
                delete lst;
                freqs_.erase(min_freq_);
            }
            min_freq_ = 1;
            // 插入结点
            Node *cur = new Node();
            cur->val_ = value;
            cur->freq_ = 1;
            cur->key_ = key;
            if (freqs_.find(cur->freq_) == freqs_.end()) {
                freqs_[cur->freq_] = new List();
            }
            lst = freqs_[cur->freq_];
            // 从尾部插入
            // ++cur->freq_;
            cur->pre_ = lst->vtail_->pre_;
            lst->vtail_->pre_->next_ = cur;
            cur->next_ = lst->vtail_;
            lst->vtail_->pre_ = cur;
            map_[key] = cur;
        } else {
            // 最小频率会变为 1
            min_freq_ = 1;
            // List *lst = freqs_[min_freq_];
            List *lst;
            // 插入结点
            Node *cur = new Node();
            cur->val_ = value;
            cur->freq_ = 1;
            cur->key_ = key;
            if (freqs_.find(cur->freq_) == freqs_.end()) {
                freqs_[cur->freq_] = new List();
            }
            lst = freqs_[cur->freq_];
            // 从尾部插入
            // ++cur->freq_;
            cur->pre_ = lst->vtail_->pre_;
            lst->vtail_->pre_->next_ = cur;
            cur->next_ = lst->vtail_;
            lst->vtail_->pre_ = cur;
            map_[key] = cur;
            ++cnt_;
        }
    }

  private:
    unordered_map<int, Node *> map_;
    unordered_map<int, List *> freqs_;
    int cap_;
    int min_freq_ = INT_MAX;
    int cnt_ = 0;
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
