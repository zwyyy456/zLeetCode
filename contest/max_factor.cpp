#include <iostream>
using namespace std;

int max_factor(int a, int b) {
    while (a % b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return b;
}

int main() {
    cout << 12 % 30 << endl;
    cout << max_factor(12, 30) << endl;
    return 0;
}