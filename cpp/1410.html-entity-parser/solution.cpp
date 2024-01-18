// Created by zwyyy456 at 2023/11/23 23:29
// leetgo: 1.3.8
// https://leetcode.com/problems/html-entity-parser/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    string entityParser(string text) {
        int n = text.size();
        int state = 0;
        string res;
        for (int i = 0; i < n; ++i) {
            if (state == 0) {
                if (text[i] == '&') {
                    state = 1;
                    res.push_back(text[i]);
                    // continue;
                }
                res.push_back(text[i]);
            } else if (state == 1) {
                if (i + 2 < text.size() && text.substr(i + 1, 2) == "gt") {
                    state = 0;
                    res.pop_back();
                    res.push_back('>');
                    i += 2;
                } else if (i + 2 < text.size() && text.substr(i + 1, 2) == "lt") {
                    state = 0;
                    res.pop_back();
                    res.push_back('<');
                    i += 2;
                } else if (i + 4 < text.size() && text.substr(i + 1, 4) == "quot") {
                    state = 0;
                    res.pop_back();
                    res.push_back('"');
                    i += 4;
                } else if (i + 4 < text.size() && text.substr(i + 1, 4) == "apos") {
                    state = 0;
                    res.pop_back();
                    res.push_back('\'');
                    i += 4;
                } else if (i + 3 < text.size() && text.substr(i + 1, 3) == "amp") {
                    state = 0;
                    res.pop_back();
                    res.push_back('&');
                    i += 3;
                } else if (i + 5 < text.size() && text.substr(i + 1, 5) == "frasl") {
                    state = 0;
                    res.pop_back();
                    res.push_back('/');
                    i += 5;
                } else {
                    state = 0;
                    res.push_back(text[i]);
                }
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    string text;
    LeetCodeIO::scan(cin, text);

    Solution *obj = new Solution();
    auto res = obj->entityParser(text);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
