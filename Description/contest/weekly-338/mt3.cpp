#include <iostream>
#include <vector>
using namespace std;

// 使用树状数组
int lowbit(int x) {
	return x&(-x);
}

int get_sum(int x, vector<int> &tree_arr) {
	int sum = 0;
	while (x != 0) {
		sum += tree_arr[x];
		x -= lowbit(x);
	}
	return sum;
}

void change_arr(int x, vector<int> &tree_arr, int add) {
	while (x <= tree_arr.size()) {
		tree_arr[x] += add;
		x += lowbit(x);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> tree_arr(n + 1, 0);
	vector<int> op(m);
	vector<int> x_arr(m);
	vector<int> y_arr(m);
	vector<int> val(m + 1, 0);
	for (int i = 0; i < m; ++i) {
		cin >> op[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> x_arr[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> y_arr[i];
	}
	// 开始处理数组
	vector<int> res(m);
	for (int i = 0; i < m; ++i) {
		if (op[i] == 0) {
			// 直接查询
			res[i] = get_sum(y_arr[i], tree_arr) - get_sum(x_arr[i] - 1, tree_arr);	
		} else {
			// 要进行修改
			// 例如，7只有tree_arr[7]，tree_arr[8]包含
			int add = y_arr[i] - val[x_arr[i]];
			val[x_arr[i]] = y_arr[i];
			change_arr(x_arr[i], tree_arr, add);
		}
	}
	for (int i = 0; i < m; ++i) {
		cout << res[i] << " ";
	}	
  	return 0;
}