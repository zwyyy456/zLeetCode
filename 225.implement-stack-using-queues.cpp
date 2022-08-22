/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
#include <queue>
using std::queue;
class MyStack {
  public:
    queue<int> mq;
    MyStack() {
    }

    void push(int x) {
        mq.push(x);
    }

    int pop() {
        int len = mq.size();
        for (int i = 0; i < len - 1; i++) {
            int temp = mq.front();
            mq.pop();
            mq.push(temp);
        }
        int res = mq.front();
        mq.pop();
        return res;
    }

    int top() {
        return mq.back();
    }

    bool empty() {
        return mq.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
