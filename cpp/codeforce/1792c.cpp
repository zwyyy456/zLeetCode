#include <bits/stdc++.h>

using namespace std;

bool check(int k, vector<int> &vec) {
    int n = vec.size();
    int l = k + 1, r = n - k;
    int preidx = -1, prenum = k;
    for (int i = 0; i < n; ++i) {
        if (vec[i] > prenum + 1 && vec[i] <= r) {
            return false;
        }
        if (vec[i] == prenum + 1) {
            ++prenum;
        }
    }
    return true;
}

int solve(vector<int> &vec) {
    int l = 0, r = vec.size() / 2 + 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (!check(mid, vec)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
int main() {
    int t;
    cin >> t;
    vector<vector<int>> vecs(t);
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;
            vecs[i].push_back(tmp);
        }
    }
    for (int i = 0; i < t; ++i) {
        int res = solve(vecs[i]);
        cout << res << endl;
    }
    return 0;
}
