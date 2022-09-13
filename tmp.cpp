#include <iostream>
using std::cout;
using std::endl;

int numberOfWays(int startPos, int endPos, int k) {
        int m = (endPos - startPos) >= 0 ? (endPos- startPos) : (startPos - endPos);
        int res = 1;
        int mid = (m + k) / 2;
        cout << mid << endl;
        if ((k - m) % 2 == 1)
            return 0;
        if (k - m == 0)
            return 1;
        else {
            while (k > mid) {
                res *= k;
                cout << res << endl;
                k--;
            }
            return res;
        }
    }

int main() {
    cout << numberOfWays(1, 2, 3) << endl;
}