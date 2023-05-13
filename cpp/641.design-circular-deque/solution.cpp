// Created by zwyyy456 at 2023/05/05 10:30
// https://leetcode.com/problems/design-circular-deque/

/*
641. Design Circular Deque (Medium)
Design your implementation of the circular double-ended queue (deque).

Implement the `MyCircularDeque` class:

- `MyCircularDeque(int k)` Initializes the deque with a maximum size of `k`.
- `boolean insertFront()` Adds an item at the front of Deque. Returns `true` if the operation is
successful, or `false` otherwise.
- `boolean insertLast()` Adds an item at the rear of Deque. Returns `true` if the operation is
successful, or `false` otherwise.
- `boolean deleteFront()` Deletes an item from the front of Deque. Returns `true` if the operation is
successful, or `false` otherwise.
- `boolean deleteLast()` Deletes an item from the rear of Deque. Returns `true` if the operation is
successful, or `false` otherwise.
- `int getFront()` Returns the front item from the Deque. Returns `-1` if the deque is empty.
- `int getRear()` Returns the last item from Deque. Returns `-1` if the deque is empty.
- `boolean isEmpty()` Returns `true` if the deque is empty, or `false` otherwise.
- `boolean isFull()` Returns `true` if the deque is full, or `false` otherwise.

**Example 1:**

```
Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull",
"deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4

```

**Constraints:**

- `1 <= k <= 1000`
- `0 <= value <= 1000`
- At most `2000` calls will be made to `insertFront`, `insertLast`, `deleteFront`, `deleteLast`,
`getFront`, `getRear`, `isEmpty`, `isFull`.

*/

#include <bits/stdc++.h>
#include <iterator>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class MyCircularDeque {
  public:
    MyCircularDeque(int k) :
        k_(k), len(k + 1), front_(0), rear_(0) {
        arr_ = new int[len];
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front_ = (front_ - 1 + len) % len;
        arr_[front_] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        arr_[rear_] = value;
        rear_ = (rear_ + 1) % len;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front_ = (front_ + 1) % len;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear_ = (rear_ - 1 + len) % len;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr_[front_];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr_[(rear_ - 1 + len) % len];
    }

    bool isEmpty() {
        return front_ == rear_;
    }

    bool isFull() {
        return (rear_ + 1 - front_ + len) % len == 0;
    }

  private:
    int *arr_;
    int k_;
    int len;
    int front_;
    int rear_;
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    MyCircularDeque *obj;

    const unordered_map<string, function<void()>> methods = {
        {"MyCircularDeque", [&]() {
             int k;
             LeetCodeIO::scan(cin, k);
             cin.ignore();
             obj = new MyCircularDeque(k);
             out_stream << "null,";
         }},
        {"insertFront", [&]() {
             int value;
             LeetCodeIO::scan(cin, value);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->insertFront(value));
             out_stream << ',';
         }},
        {"insertLast", [&]() {
             int value;
             LeetCodeIO::scan(cin, value);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->insertLast(value));
             out_stream << ',';
         }},
        {"deleteFront", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->deleteFront());
             out_stream << ',';
         }},
        {"deleteLast", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->deleteLast());
             out_stream << ',';
         }},
        {"getFront", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->getFront());
             out_stream << ',';
         }},
        {"getRear", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->getRear());
             out_stream << ',';
         }},
        {"isEmpty", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->isEmpty());
             out_stream << ',';
         }},
        {"isFull", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->isFull());
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
