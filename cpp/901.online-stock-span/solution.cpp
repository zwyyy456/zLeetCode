// Created by zwyyy456 at 2023/10/07 21:04
// leetgo: 1.3.8
// https://leetcode.com/problems/online-stock-span/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class StockSpanner {
  public:
    StockSpanner() = default;

    int next(int price) {
        stocks.push_back(price);
        while (!stk.empty() && price < stocks[stk.top()]) {
            stk.pop();
        }
        int res = cur - stk.top();
        stk.push(cur++);
        return res;
    }

  private:
    stack<int> stk; // 单调递减栈
    vector<int> stocks;
    int cur = 0;
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    StockSpanner *obj;
    const unordered_map<string, function<void()>> methods = {
        {"StockSpanner", [&]() {
             cin.ignore();
             obj = new StockSpanner();
             out_stream << "null,";
         }},
        {"next", [&]() {
             int price;
             LeetCodeIO::scan(cin, price);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->next(price));
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
