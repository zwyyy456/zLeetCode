#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.length() == 0)
        return 0;
    unordered_set<char> mset;
    int l = 0;
    mset.insert(s[0]);
    int res = 1;
    for (int r = 1; r < s.size(); r++) {
        // 要考虑mset为空的情况
        if (mset.empty()) {
            l = r;
            mset.insert(s[r]);
            res = max(res, r - l + 1);
        } else {
            if (mset.find(s[r]) != mset.end()) {
                while (l <= r && mset.find(s[r]) != mset.end())
                    mset.erase(s[l++]);
            } else {
                mset.insert(s[r]);
                res = max(res, r - l + 1);
            }
        }
    }
    return res;
}

int main() {
    string s = "bbbbb";

    int res = lengthOfLongestSubstring(s);
    return 0;
}