#include <string>
using std::string;
class Solution {
  public:
    int longestContinuousSubstring(string s) {
        int len = 1;
        int max_len = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] - s[i - 1] == 1) {
                len++;
                if (len > max_len)
                    max_len = len;
            }
            else {
                len = 1;
            }
        }
        return max_len;
    }
};