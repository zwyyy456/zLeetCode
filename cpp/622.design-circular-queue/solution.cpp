// Created by zwyyy456 at 2023/05/17 10:09
// https://leetcode.com/problems/design-circular-queue/

/*
622. Design Circular Queue (Medium)
Design your implementation of the circular queue. The circular queue is a linear data structure in
which the operations are performed based on FIFO (First In First Out) principle, and the last
position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the
queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if
there is a space in front of the queue. But using the circular queue, we can use the space to store
new values.

Implement the `MyCircularQueue` class:

- `MyCircularQueue(k)` Initializes the object with the size of the queue to be `k`.
- `int Front()` Gets the front item from the queue. If the queue is empty, return `-1`.
- `int Rear()` Gets the last item from the queue. If the queue is empty, return `-1`.
- `boolean enQueue(int value)` Inserts an element into the circular queue. Return `true` if the
operation is successful.
- `boolean deQueue()` Deletes an element from the circular queue. Return `true` if the operation is
successful.
- `boolean isEmpty()` Checks whether the circular queue is empty or not.
- `boolean isFull()` Checks whether the circular queue is full or not.

You must solve the problem without using the built-in queue data structure in your programming
language.

**Example 1:**

```
Input
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue",
"enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 3, true, true, true, 4]

Explanation
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4

```

**Constraints:**

- `1 <= k <= 1000`
- `0 <= value <= 1000`
- At most `3000` calls will be made to `enQueue`, `deQueue`, `Front`, `Rear`, `isEmpty`, and
`isFull`.

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class MyCircularQueue {
  public:
    MyCircularQueue(int k) :
        myq(k + 1), head(0), tail(0) {
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        myq[tail] = value;
        tail = (tail + 1 + myq.size()) % myq.size();
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head = (head + 1 + myq.size()) % myq.size();
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return myq[head];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        int rear = (tail - 1 + myq.size()) % myq.size();
        return myq[rear];
    }

    bool isEmpty() {
        return head == tail;
    }

    bool isFull() {
        return (tail + 1 - head + myq.size()) % myq.size() == 0;
    }

  private:
    vector<int> myq;
    int head;
    int tail;
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    MyCircularQueue *obj;

    const unordered_map<string, function<void()>> methods = {
        {"MyCircularQueue", [&]() {
             int k;
             LeetCodeIO::scan(cin, k);
             cin.ignore();
             obj = new MyCircularQueue(k);
             out_stream << "null,";
         }},
        {"enQueue", [&]() {
             int value;
             LeetCodeIO::scan(cin, value);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->enQueue(value));
             out_stream << ',';
         }},
        {"deQueue", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->deQueue());
             out_stream << ',';
         }},
        {"Front", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->Front());
             out_stream << ',';
         }},
        {"Rear", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->Rear());
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
