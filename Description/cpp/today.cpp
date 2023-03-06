class Solution {
  public:
    string printBin(double num) {
        string res = "0.";
        for (int i = 0; i < 6; ++i) { // 至多循环 6 次
            num *= 2;
            if (num < 1)
                res += '0';
            else {
                res += '1';
                if (--num == 0)
                    return res;
            }
        }
        return "ERROR";
    }
};