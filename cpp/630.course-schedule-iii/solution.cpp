// Created by zwyyy456 at 2023/09/11 10:46
// leetgo: 1.3.8
// https://leetcode.com/problems/course-schedule-iii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int bfind(vector<vector<int>> &courses, int startt) {
        int l = 0, r = courses.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (courses[mid][1] <= startt) {
                l = mid + 1;
            } else {
                r = mid;
            }
            return l;
        }
    }
    int dfs(vector<vector<int>> &courses, int cur, int time) {
    	if (cur == courses.size()) {
    		return 0;
    	}
    	// 上当前课程 与 不上
    	if (time + courses[cur][0] > courses[cur][1]) {
    		return dfs(courses, cur + 1, time);
    	}
    	return max(1 + dfs(courses, cur + 1, time + courses[cur][0]), dfs(courses, cur + 1, time));
    }
    int scheduleCourse(vector<vector<int>> &courses) {
        auto cmp = [](vector<int> &v1, vector<int> &v2) {
            return v1[1] <= v2[1];
        };
        sort(courses.begin(), courses.end(), cmp);
        int n = courses.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int endt = courses[i - 1][1];
            int startt = courses[i - 1][1] - courses[i - 1][0];
            if (startt < 0) {
                dp[i] = dp[i - 1];
            } else {
                int idx = bfind(courses, startt);
                dp[i] = max(dp[idx] + 1, dp[i - 1]);
            }
        }
        return dp[n];
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<vector<int>> courses;
    LeetCodeIO::scan(cin, courses);

    Solution *obj = new Solution();
    auto res = obj->scheduleCourse(courses);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
