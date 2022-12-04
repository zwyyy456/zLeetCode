#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> mset;
    mset.insert(10);
    mset.insert(5);
    mset.insert(15);
    cout << *mset.rbegin() << endl;
}