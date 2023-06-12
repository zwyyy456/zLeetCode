// Created by zwyyy456 at 2023/06/02 14:41
// https://leetcode.com/problems/lru-cache/

/*
146. LRU Cache (Medium)
Design a data structure that follows the constraints of a **[Least Recently Used (LRU)
cache](https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU)**.

Implement the `LRUCache` class:

- `LRUCache(int capacity)` Initialize the LRU cache with **positive** size `capacity`.
- `int get(int key)` Return the value of the `key` if the key exists, otherwise return `-1`.
- `void put(int key, int value)` Update the value of the `key` if the `key` exists. Otherwise, add
the `key-value` pair to the cache. If the number of keys exceeds the `capacity` from this operation,
**evict** the least recently used key.

The functions `get` and `put` must each run in `O(1)` average time complexity.

**Example 1:**

```
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

```

**Constraints:**

- `1 <= capacity <= 3000`
- `0 <= key <= 10⁴`
- `0 <= value <= 10⁵`
- At most `2 * 10⁵` calls will be made to `get` and `put`.

*/

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
class LRUCache {
  public:
    LRUCache(int capacity) :
        lst(new List()), cap_(capacity) {
    }

    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;
        }
        Node *node = hash[key];
        lst->Delete(node);
        lst->Insert(node);
        return node->val_;
    }

    void put(int key, int value) {
        if (hash.find(key) != hash.end()) {
            // key 已经存在
            Node *node = hash[key];
            node->val_ = value;
            node->key_ = key;
            get(key);
            return;
        }
        // key 不存在，需要插入
        if (cnt_ == cap_) {
            // 这里先插入或者先删除都能满足题义，我选择先插入，再删除（防止 capacity 为 0 的极限情况）
            Node *node = new Node(value, key);
            lst->Insert(node);
            hash[key] = node;

            // 删除头结点
            Node *head = lst->vhead_->next_;
            lst->Delete(head);
            hash.erase(head->key_);
            delete head;
            head = nullptr;
        } else {
            // 直接插入即可
            Node *node = new Node(value, key);
            lst->Insert(node);
            hash[key] = node;
            // 记得修改数量
            ++cnt_;
        }
    }

  private:
    unordered_map<int, Node *> hash;
    List *lst;
    int cnt_ = 0;
    int cap_;
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    LRUCache *obj;

    const unordered_map<string, function<void()>> methods = {
        {"LRUCache", [&]() {
             int capacity;
             LeetCodeIO::scan(cin, capacity);
             cin.ignore();
             obj = new LRUCache(capacity);
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
