// Created by zwyyy456 at 2023/02/25 14:02
// https://leetcode.com/problems/stone-game-ii/

/*
1140. Stone Game II (Medium)

Alice and Bob continue their games with piles of stones.  There are a number of piles **arranged in
a row**, and each pile has a positive integer number of stones `piles[i]`.  The objective of the
game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.  Initially, `M = 1`.

On each player's turn, that player can take **all the stones** in the **first** `X` remaining piles,
where `1 <= X <= 2M`.  Then, we set `M = max(M, X)`.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

**Example 1:**

```
Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2
piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning,
then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we
return 10 since it's larger.

```

**Example 2:**

```
Input: piles = [1,2,3,4,5,100]
Output: 104

```

**Constraints:**

- `1 <= piles.length <= 100`
- `1 <= piles[i] <= 10⁴`
*/

// @lc code=begin
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct Node {
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

// @lc code=end
