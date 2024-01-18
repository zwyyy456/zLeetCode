// 二分答案
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;
pair<int, int> start;
pair<int, int> target;

bool bfs(vector<vector<int>> &grid, int mid) {
}

int main() {
    int left = 0;
    int n;
    cin >> n;
    int k;
    cin >> k;
    int right = 300000;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<vector<int>>> board(n, vector<vector<int>>(n, vector<int>(3, 0)));
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x;
        cin >> y;
        grid[x][y] = -1; // -1 说明有怪物
    }

    cin >> start.first;
    cin >> start.second;
    cin >> target.first;
    cin >> target.second;
    for (int i = 0; i < n; ++i) {
        for (int)
    }
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (bfs(grid, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}