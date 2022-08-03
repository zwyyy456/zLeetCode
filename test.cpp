#include <iostream>
#include <unordered_set>
using std::unordered_set;
int mysum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += (n % 10) * (n % 10);
        n = n / 10;
    }
    return sum;
}
bool isHappy(int n) {
    unordered_set<int> happy;
    int sum = mysum(n);
    while (sum != 1) {
        if (happy.find(sum) != happy.end()) {
            return false;
        } else {
            happy.insert(sum);
            sum = mysum(sum);
        }
    }
    return true;
}

int main() {
    int n = isHappy(19);
    std::cout << isHappy(19) << "\n";
}
