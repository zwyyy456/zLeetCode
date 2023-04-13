#include <vector>
#include <iostream>
using namespace std;

int change1(int le, vector<int> &nums, double sum, int cnt) {
	if (le == 0) {
		sum -= nums[cnt];
	} else if (le == 1) {
		sum += nums[cnt];
	} else if (le == 2) {
		sum -= 
	}
}
int main() {
  int n, m;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  cin >> m;
  vector<char> ops(n - 1, '+');
  char tmp[4] = {'+', '-', '*', '/'};
  vector<double> res(n);
  double sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += nums[i];
  }
  for (int i = 0; i < m; ++i) {
    int cnt;
    char op;
    cin >> cnt >> op;
    int j = 0, k = 0; // j表示新的，k表示原来的
    for (int le = 0; le < 4; ++le) {
      if (op == tmp[le]) {
        j = le;
      }
      if (ops[cnt - 1] == tmp[le]) {
        k = le;
      }
    }
  }
}