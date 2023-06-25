#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
int add(char c1, char c2) {
    if (c1 == '!') {
        if (c2 == '!') {
            return 0;
        } else if (c2 == '@') {
            return 13;
        } else if (c2 == '#') {
            return 4;
        }
    } else if (c1 == '@') {
        if (c2 == '@') {
            return 7;
        } else if (c2 == '#') {
            return 20;
        } else if (c2 == '!') {
            return 13;
        }
    } else if (c1 == '#') {
        if (c2 == '#') {
            return 5;
        } else if (c2 == '!') {
            return 4;
        } else {
            return 20;
        }
    } else {
        return c1 - '0' + c2 - '0';
    }
}
string sum(vector<char> &s1_front, vector<char> &s2_front) {
    int i1 = s1_front.size();
    int i2 = s2_front.size();
    int carry_front = 0;
    string res_front;
    while (i1 >= 0 || i2 >= 0 || carry_front != 0) {
        char c1 = i1 >= 0 ? s1_front[i1] : '0';
        char c2 = i2 >= 0 ? s2_front[i2] : '0';
        int sum = add(c1, c2) + carry_front;
        carry_front = sum / 10;
        res_front = to_string(sum % 10) + res_front;
        --i1;
        --i2;
    }
}
int main() {
    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++ output here. For example:cout<<____<<endl;
    int len;
    cin >> len;
    string s;
    cin >> s;
    vector<char> s1_front;
    vector<char> s1_back;
    vector<char> s2_front;
    vector<char> s2_back;
    int i = 0;
    for (i = 0; s[i] != '.' && s[i] != '+'; ++i) {
        s1_front.push_back(s[i]);
    }
    if (s[i] != '+') {
        // 说明存在 点号
        for (i = i + 1; s[i] != '+'; ++i) {
            s1_back.push_back(s[i]);
        }
    }
    for (i = i + 1; s[i] != '.' && i < len; ++i) {
        s2_front.push_back(s[i]);
    }
    if (i < len) {
        for (i = i + 1; i < len; ++i) {
            s2_back.push_back(s[i]);
        }
    }
    string res;
    string res_front;
    string res_back;
    // s1 比 s2 长
    if (s1_front.size() < s2_front.size()) {
        swap(s1_front, s2_front);
    }
    res_front = sum(s1_front, s2_front);

    if (s1_back.size() < s2_back.size()) {
        swap(s1_back, s2_back);
    }
    res_back = sum(s1_back, s2_back);

    if (res_back.size() > s1_back.size()) {
        vector<char> res_tmp(res_front.begin(), res_front.end());
        vector<char> res_tmp2{res_back[0]};
        res_front = sum(res_tmp, res_tmp2);
    }
    cout << res_front + "." + res_back << endl;
}
