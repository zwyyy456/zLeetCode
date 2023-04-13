#include <memory>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int n = 42;
	allocator<string> alloc;
	auto p = alloc.allocate(n);
	string str;
	auto q = p;
	while(cin >> str && q != p + n) {
		alloc.construct(q++, str);
	}
	alloc.deallocate(p, n);
}