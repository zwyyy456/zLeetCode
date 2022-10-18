#include <iostream>
#include <vector>
#include <math.h>
using std::cout;
using std::endl;
using std::vector;

int reverse(int a) {
    vector<int> tmp;
    while (a != 0) {
        tmp.push_back(a % 10);
        a = a / 10;
    }
    int sz = tmp.size();
    int sum = 0;
    for (int i = 0; i < sz; i++) {
        cout << tmp[i] << "\n";
        sum += tmp[i] * pow(10, sz - i - 1);
    }
    return sum;
}
int main() {
    cout <<  reverse(23) << "\n" << reverse(10) << "\n" << reverse(230) << endl;
    return 0;
    
}