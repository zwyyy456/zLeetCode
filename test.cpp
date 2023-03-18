#include <iostream>
#include <string>
using std::string;

void getNext(int *next, const string &s) {
    int j = -1;
    next[0] = j;
    for (int i = 1; i < s.size(); i++) {
        // next[j + 1]指向匹配好的前缀的下一个字符
        // i指向后缀末尾位置
        while (j >= 0 && s[i] != s[j + 1]) {
            j = next[j];
        }
        if (s[i] == s[j + 1]) {
            j++;
        }
        next[i] = j;
    }
    for (int i = 0; i < s.size(); i++) {
        std::cout << next[i] << std::endl;
    }
}

int main() {
    string s = "aabaaf";
    int next[s.size()];
    getNext(next, s);
    return 0;
}
