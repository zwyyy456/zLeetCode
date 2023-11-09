// Created by zwyyy456 at 2023/11/05 10:54
// leetgo: 1.3.8
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
struct Node {
    Node() :
        isend_(false) {
        arr[0] = nullptr;
        arr[1] = nullptr;
    }
    Node *arr[2];
    bool isend_;
    void insert(int num) {
        Node *cur = this;
        for (int i = 31; i >= 0; --i) {
            int idx = ((num >> i) & 0x1);
            if (cur->arr[idx] == nullptr) {
                arr[idx] = new Node();
            }
            cur = cur->arr[idx];
        }
        cur->isend_ = true;
    }
    int count(int num) {
        Node *cur = this;
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            int a = (num >> i) & 0x1;
            int b = 1 - a;
            if (cur->arr[b] != nullptr) {
            	res |= (1 << i);
            	cur = cur->arr[b];
            } else {
            	cur = cur->arr[a];
            }
        }
        return res;
    }
};

class Solution {
  public:
    int findMaximumXOR(vector<int> &nums) {
        Node *tree = new Node();
        for (int num : nums) {
            tree->insert(num);
        }
        int res = 0;
        for (int num : nums) {
        	res = max(res, tree->count(num));
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();
    auto res = obj->findMaximumXOR(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
