// Created by zwyyy456 at 2023/05/04 15:36
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
    Node *pre_;
    Node *next_;
    int val_;
    int key_;
    Node() :
        pre_(nullptr), next_(nullptr),  val_(0), key_(0){};
};
class LRUCache {
  public:
    LRUCache(int capacity) :
        cap_(capacity) {
        dum_head_ = new Node();
        dum_tail_ = new Node();
        dum_head_->next_ = dum_tail_;
        dum_tail_->pre_ = dum_head_;
    }

    int get(int key) {
        if (ump.find(key) == ump.end()) {
            return -1;
        }
        Node *tmp = ump[key];
        int val = tmp->val_;
        // 删除该节点，然后再放入链表最末端
        tmp->pre_->next_ = tmp->next_;
        tmp->next_->pre_ = tmp->pre_;
        // 放入链表的最末端
        tmp->next_ = dum_tail_;
        tmp->pre_ = dum_tail_->pre_;
        tmp->next_->pre_ = tmp;
        tmp->pre_->next_ = tmp;
        return val;
    }

    void put(int key, int value) {
        if (ump.find(key) != ump.end()) {
            ump[key]->val_ = value;
            get(key);
        } else {
            Node *tmp = new Node();
            tmp->val_ = value;
            tmp->key_ = key;
            // 放入链表的最末端
            tmp->next_ = dum_tail_;
            tmp->pre_ = dum_tail_->pre_;
            tmp->next_->pre_ = tmp;
            tmp->pre_->next_ = tmp;
            ump[key] = tmp;
            ++size_;
            if (size_ > cap_) {
            	Node *head = dum_head_->next_;
            	head->pre_->next_ = head->next_;
            	head->next_->pre_ = head->pre_;
            	--size_;
                int tmp_key = head->key_;
                ump.erase(tmp_key);
                delete(head);
            }
        }
    }

  private:
    Node *dum_head_, *dum_tail_;
    unordered_map<int, Node *> ump;
    int size_ = 0;
    int cap_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

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
