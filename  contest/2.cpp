#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string largesPalindromic(string num) {
    int a[10] = {0};
    string res;
    for (char c : num)
        a[c - '0']++;
    //注意回文数中间怎么处理
    int odd_i = 10;
    for (int i = 0; i < 10; i++) {
        if (a[i] % 2 == 1)
            odd_i = i;
        for (int j = 0; j < a[i] / 2; j++)
            res.push_back((char)(i + '0'));
    }
    string tail = res;
    reverse(res.begin(), res.end());
    string mid;
    if (res[0] == '0')
        mid.push_back((char)(odd_i + '0'));
    if (res[0] == '0') {
        if (mid.empty())
            res = mid;
    } else {
        res = res + mid + tail;
    }
    return res;
}

int main() {
    string res = largesPalindromic("00001105");
    cout << res << endl;
    return 0;
}