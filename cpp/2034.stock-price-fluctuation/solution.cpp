// Created by zwyyy456 at 2023/05/09 10:40
// https://leetcode.com/problems/stock-price-fluctuation/

/*
2034. Stock Price Fluctuation  (Medium)
You are given a stream of **records** about a particular stock. Each record contains a **timestamp**
and the corresponding **price** of the stock at that timestamp.

Unfortunately due to the volatile nature of the stock market, the records do not come in order. Even
worse, some records may be incorrect. Another record with the same timestamp may appear later in the
stream **correcting** the price of the previous wrong record.

Design an algorithm that:

- **Updates** the price of the stock at a particular timestamp, **correcting** the price from any
previous records at the timestamp.
- Finds the **latest price** of the stock based on the current records. The **latest price** is the
price at the latest timestamp recorded.
- Finds the **maximum price** the stock has been based on the current records.
- Finds the **minimum price** the stock has been based on the current records.

Implement the `StockPrice` class:

- `StockPrice()` Initializes the object with no price records.
- `void update(int timestamp, int price)` Updates the `price` of the stock at the given `timestamp`.
- `int current()` Returns the **latest price** of the stock.
- `int maximum()` Returns the **maximum price** of the stock.
- `int minimum()` Returns the **minimum price** of the stock.

**Example 1:**

```
Input
["StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"]
[[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]
Output
[null, null, null, 5, 10, null, 5, null, 2]

Explanation
StockPrice stockPrice = new StockPrice();
stockPrice.update(1, 10); // Timestamps are [1] with corresponding prices [10].
stockPrice.update(2, 5);  // Timestamps are [1,2] with corresponding prices [10,5].
stockPrice.current();     // return 5, the latest timestamp is 2 with the price being 5.
stockPrice.maximum();     // return 10, the maximum price is 10 at timestamp 1.
stockPrice.update(1, 3);  // The previous timestamp 1 had the wrong price, so it is updated to 3.
                          // Timestamps are [1,2] with corresponding prices [3,5].
stockPrice.maximum();     // return 5, the maximum price is 5 after the correction.
stockPrice.update(4, 2);  // Timestamps are [1,2,4] with corresponding prices [3,5,2].
stockPrice.minimum();     // return 2, the minimum price is 2 at timestamp 4.

```

**Constraints:**

- `1 <= timestamp, price <= 10⁹`
- At most `10⁵` calls will be made **in total** to `update`, `current`, `maximum`, and `minimum`.
- `current`, `maximum`, and `minimum` will be called **only after** `update` has been called **at
least once**.

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class StockPrice {
  public:
    StockPrice() {
        latest_time = 0;
    }

    void update(int timestamp, int price) {
        if (time_price.find(timestamp) == time_price.end()) {
            // 直接插入即可
            time_price[timestamp] = price;
            ++price_num[price];
        } else {
            int pre = time_price[timestamp];
            --price_num[pre];
            if (price_num[pre] == 0) {
            	price_num.erase(pre);
            }
            time_price[timestamp] = price;
            ++price_num[price];
        }
        latest_time = max(latest_time, timestamp);
    }

    int current() {
        return time_price[latest_time];
    }

    int maximum() {
        return (--price_num.end())->first;
    }

    int minimum() {
        return price_num.begin()->first;
    }

  private:
    unordered_map<int, int> time_price;
    map<int, int> price_num;
    int latest_time;
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
