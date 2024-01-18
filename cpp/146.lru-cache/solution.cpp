// Created by zwyyy456 at 2023/11/23 09:41
// leetgo: 1.3.8
// https://leetcode.com/problems/lru-cache/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

struct Node {
    Node *next;
    Node *prev;
    int val_;
    Node() = default;
    Node(int val) :
        val_(val) {
    }
};
class List {
  public:
    List() :
        vhead(new Node), vtail(new Node) {
        vhead->next = vtail;
        vtail->prev = vhead;
    }
    void Remove(Node *target) {
        if (IsEmpty()) {
            return;
        }
        target->prev->next = target->next;
        target->next->prev = target->prev;
        target->next = nullptr;
        target->prev = nullptr;
    }
    void Insert(Node *toadd) {
        // 插入到链表末尾
        Node *tail = vtail->prev;
        tail->next = toadd;
        toadd->prev = tail;
        toadd->next = vtail;
        vtail->prev = toadd;
    }
    void Remove() {
        if (IsEmpty()) {
            return;
        }
        auto *head = vhead->next;
        Remove(vhead->next);
        delete head;
    }

  private:
    Node *vhead;
    Node *vtail;
    bool IsEmpty() {
        return vhead->next == vtail;
    }
};
class LRUCache {
  public:
    LRUCache(int capacity) :
        lst(new List()), cap_(capacity), size_(0) {
    }

    int get(int key) {
        if (key2ptr.find(key) == key2ptr.end()) {
            return -1;
        }
        auto *ptr = key2ptr.at(key);
        lst->Remove(ptr);
        lst->Insert(ptr);
        return ptr->val_;
    }

    void put(int key, int value) {
        if (key2ptr.find(key) == key2ptr.end()) {
            // 要插入
            if (size_ == cap_) {
                lst->Remove();
            }
            auto *node = new Node(value);
            lst->Insert(node);
            key2ptr[key] = node;
            ++size_;
        } else {
            auto *ptr = key2ptr.at(key);
            ptr->val_ = value;
            get(key);
        }
    }

  private:
    List *lst;
    unordered_map<int, Node *> key2ptr;
    int cap_;
    int size_;
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
    cin >> ws;
    out_stream << '[';
    for (auto &&method_name : method_names) {
        cin.ignore(2);
        methods.at(method_name)();
    }
    cin.ignore();
    out_stream.seekp(-1, ios_base::end);
    out_stream << ']';
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
