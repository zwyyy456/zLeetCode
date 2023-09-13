// Created by zwyyy456 at 2023/09/10 12:25
// leetgo: 1.3.8
// https://leetcode.com/problems/course-schedule-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> next(numCourses);
        vector<int> indeg(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            int x = prerequisites[i][0], y = prerequisites[i][1];
            next[y].push_back(x);
            ++indeg[x];
        }
        vector<int> res;
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto idx = q.front();
            q.pop();
            res.push_back(idx);
            for (int cour : next[idx]) {
                if (--indeg[cour] == 0) {
                    q.push(cour);
                }
            }
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int numCourses;
    LeetCodeIO::scan(cin, numCourses);
    vector<vector<int>> prerequisites;
    LeetCodeIO::scan(cin, prerequisites);

    Solution *obj = new Solution();
    auto res = obj->findOrder(numCourses, prerequisites);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
