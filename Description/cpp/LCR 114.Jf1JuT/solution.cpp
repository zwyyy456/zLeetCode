// Created by zwyyy456 at 2023/08/16 09:23
// leetgo: 1.3.5
// https://leetcode.cn/problems/Jf1JuT/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    string alienOrder(vector<string> &words) {
        vector<vector<int>> graph(26);
        vector<int> in_deg(26);
        unordered_set<int> chars;
        int n = words.size();
        for (auto &str : words) {
            for (char c : str) {
                chars.insert(c - 'a');
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            int l = 0, r = 0;
            while (l < words[i].size() && l < words[i + 1].size()) {
                if (words[i][l] != words[i + 1][l]) {
                    break;
                }
                ++l;
            }
            if (l < words[i].size() && l < words[i + 1].size()) {
                graph[words[i][l] - 'a'].push_back(words[i + 1][l] - 'a');
                ++in_deg[words[i + 1][l] - 'a'];
            }
        }
        // 进行拓扑排序
        queue<int> q;
        string res;
        for (int i = 0; i < 26; ++i) {
            if (in_deg[i] == 0 && chars.find(i) != chars.end()) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            res.push_back(i + 'a');
            for (auto idx : graph[i]) {
                if (--in_deg[idx] == 0) {
                    q.push(idx);
                }
            }
        }
        if (res.size() < chars.size()) {
            string nulstr;
            return nulstr;
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> words;
    LeetCodeIO::scan(cin, words);

    Solution *obj = new Solution();
    auto res = obj->alienOrder(words);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
