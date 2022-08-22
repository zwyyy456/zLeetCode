#include <string>
using std::string;
class Solution {
  public:
    void reverseString(string &s, int i, int j) {
        if (i < 0 || j > s.size() - 1)
            return;
        else {
            while (i <= j) {
                char temp = s[i];
                s[i++] = s[j];
                s[j--] = temp;
            }
        }
    }
    string reverseLeftWords(string s, int n) {
        int len = s.size();
        reverseString(s, 0, len - 1);
        reverseString(s, 0, len - n - 1);
        reverseString(s, len - n, len - 1);
        return s;
    }
};