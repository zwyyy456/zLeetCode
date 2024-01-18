// Created by zwyyy456 at 2024/01/16 13:18
// leetgo: 1.3.8
// https://leetcode.com/problems/insert-delete-getrandom-o1/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class RandomizedSet {
  public:
    RandomizedSet() {
    }

    bool insert(int val) {
    }

    bool remove(int val) {
    }

    int getRandom() {
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    RandomizedSet *obj;
    const unordered_map<string, function<void()>> methods = {
        {"RandomizedSet", [&]() {
             cin.ignore();
             obj = new RandomizedSet();
             out_stream << "null,";
         }},
        {"insert", [&]() {
             int val;
             LeetCodeIO::scan(cin, val);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->insert(val));
             out_stream << ',';
         }},
        {"remove", [&]() {
             int val;
             LeetCodeIO::scan(cin, val);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->remove(val));
             out_stream << ',';
         }},
        {"getRandom", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->getRandom());
             out_stream << ',';
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
