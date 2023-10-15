// Created by zwyyy456 at 2023/10/08 12:16
// leetgo: 1.3.8
// https://leetcode.com/problems/stock-price-fluctuation/

#include <bits/stdc++.h>
#include <climits>
#include <ctime>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class StockPrice {
  public:
    StockPrice() {
    }

    void update(int timestamp, int price) {
        if (stock.find(timestamp) == stock.end()) {
            ++prices[price];
            --prices[stock[timestamp]];
            if (prices[stock[timestamp]] == 0) {
                prices.erase(stock[timestamp]);
            }
        } else {
            ++prices[price];
        }
        stock[timestamp] = price;
        cur = max(cur, timestamp);
    }

    int current() {
        return stock[cur];
    }

    int maximum() {
        return (--prices.end())->first;
    }

    int minimum() {
        return prices.begin()->first;
    }

  private:
    map<int, int> prices; // 股票价格与对应的计数
    int cur = 0;
    unordered_map<int, int> stock;
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    StockPrice *obj;
    const unordered_map<string, function<void()>> methods = {
        {"StockPrice", [&]() {
             cin.ignore();
             obj = new StockPrice();
             out_stream << "null,";
         }},
        {"update", [&]() {
             int timestamp;
             LeetCodeIO::scan(cin, timestamp);
             cin.ignore();
             int price;
             LeetCodeIO::scan(cin, price);
             cin.ignore();
             obj->update(timestamp, price);
             out_stream << "null,";
         }},
        {"current", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->current());
             out_stream << ',';
         }},
        {"maximum", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->maximum());
             out_stream << ',';
         }},
        {"minimum", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->minimum());
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
