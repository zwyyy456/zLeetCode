// Created by zwyyy456 at 2023/10/09 09:06
// leetgo: 1.3.8
// https://leetcode.com/problems/split-with-minimum-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int splitNum(int num) {
        vector<int> numbers;
        while (num != 0) {
            numbers.push_back(num % 10);
            num /= 10;
        }
        sort(numbers.begin(), numbers.end());
        int num1 = 0, num2 = 0;
        int cnt = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            if (i % 2 == 0) {
                num1 = num1 * 10 + numbers[i];
            } else {
                num2 = num2 * 10 + numbers[i];
            }
        }
        return num1 + num2;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int num;
    LeetCodeIO::scan(cin, num);

    Solution *obj = new Solution();
    auto res = obj->splitNum(num);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
