#include "bits/stdc++.h"
using namespace std;

pair<int, int> dfs(vector<int> &happ, vector<vector<int>> &sub, int master) {
    // 来，不来
    if (sub[master].empty()) {
        return {happ[master], 0};
    }
    int n = sub[master].size();
    vector<pair<int, int>> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = dfs(happ, sub, sub[master][i]);
    }
    // master 到了
    int arrive = happ[master], not_arrive = 0;
    for (int i = 0; i < n; ++i) {
        arrive += res[i].second;
        not_arrive += max(res[i].first, res[i].second);
    }
    return {arrive, not_arrive};
}

int main() {
    int n;
    cin >> n;
    vector<int> happ(n + 1);
    vector<vector<int>> sub(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> happ[i];
    }
    int master = 1;
    for (int i = 1; i <= n; ++i) {
        int l, k;
        cin >> l;
        cin >> k;
        sub[k].push_back(l);
        if (master == l) {
            master = k;
        }
    }
    auto [in, not_in] = dfs(happ, sub, master);
    cout << max(in, not_in) << endl;
    return 0;
}