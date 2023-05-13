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
int main() {
    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++ output here. For example:cout<<____<<endl;
    int len;
    cin >> len;
    string s;
    cin >> s;
    vector<char> s1_front;
    int num1_front, num1_back, num2_front, num2_back;
    vector<char> s1_back;
    vector<char> s2_front;
    vector<char> s2_back;
    int i = 0;
    unordered_map<char, set<int>> char1_front;
    unordered_map<char, set<int>> char1_back;
    unordered_map<char, set<int>> char2_front;
    unordered_map<char, set<int>> char2_back;
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
    int carry_front = 0;
    int i1 = s1_front.size() - 1;
    int i2 = s2_front.size() - 1;
    while (i1 >= 0 || i2 >= 0 || carry_front != 0) {
        char c1 = i1 >= 0 ? s1_front[i1] : '0';
        char c2 = i2 >= 0 ? s2_front[i2] : '0';
        int sum = add(c1, c2) + carry_front;
        carry_front = sum / 10;
        res_front = to_string(sum % 10) + res_front;
    }
    if (s1_back.size() < s2_back.size()) {
        swap(s1_back, s2_back);
    }
    i1 = s1_back.size() - 1;
    i2 = s2_back.size() - 1;
    carry_front = 0;
    while (i1 >= 0 || i2 >= 0 || carry_front != 0) {
        char c1 = i1 >= 0 ? s1_back[i1] : '0';
        char c2 = i2 >= 0 ? s2_back[i2] : '0';
        int sum = add(c1, c2) + carry_front;
        carry_front = sum / 10;
        res_back = to_string(sum % 10) + res_back;
    }
    cout << res_front + "." + res_back << endl;
}
