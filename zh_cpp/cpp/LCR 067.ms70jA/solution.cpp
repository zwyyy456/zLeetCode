// Created by zwyyy456 at 2023/08/07 18:01
// leetgo: 1.3.1
// https://leetcode.cn/problems/ms70jA/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Trie {
  public:
    Trie() :
        arr(2) {
    }

    void Insert(int num) {
        Trie *cur = this;
        for (int i = 30; i >= 0; --i) {
            int tmp = (num >> i & 1);
            // cout << tmp << endl;
            if (cur->arr[tmp] == nullptr) {
                cur->arr[tmp] = new Trie();
                cur = cur->arr[tmp];
            } else {
                cur = cur->arr[tmp];
            }
        }
    }
    int find(int num) {
        int res = 0;
        Trie *cur = this;
        for (int i = 30; i >= 0; --i) {
            int tmp = (num >> i) & 1;
            // cout << tmp << " " << num << endl;
            if (cur->arr[1 - tmp] != nullptr) {
                res += (1 << i);
                cur = cur->arr[1 - tmp];
            } else {
                cur = cur->arr[tmp];
            }
        }
        return res;
    }

  private:
    vector<Trie *> arr;
};
class Solution {
  public:
    int findMaximumXOR(vector<int> &nums) {
        // Trie
        if (nums.size() == 1) {
            return 0;
        }
        Trie *trie = new Trie;
        for (int num : nums) {
            trie->Insert(num);
        }
        int res = 0;
        for (int num : nums) {
            res = max(res, trie->find(num));
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
    cout << "output : " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
