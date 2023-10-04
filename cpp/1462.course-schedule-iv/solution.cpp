// Created by zwyyy456 at 2023/09/12 10:37
// leetgo: 1.3.8
// https://leetcode.com/problems/course-schedule-iv/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries) {
        vector<vector<int>> ispre(numCourses, vector<int>(numCourses, 0));
        vector<vector<int>> graph(numCourses);
        vector<int> indeg(numCourses);
        for (auto &vec : prerequisites) {
            int x = vec[0], y = vec[1];
            graph[x].push_back(y);
            ++indeg[y];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int next : graph[cur]) {
                ispre[cur][next] = 1;
                for (int i = 0; i < numCourses; ++i) {
                    if (ispre[next][i] == 1) {
                        ispre[cur][i] = 1;
                    }
                }
            }
        }
        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto &qry : queries) {
            ans.push_back(ispre[qry[0]][qry[1]] == 1);
        }
        return ans;
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
    vector<vector<int>> queries;
    LeetCodeIO::scan(cin, queries);

    Solution *obj = new Solution();
    auto res = obj->checkIfPrerequisite(numCourses, prerequisites, queries);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
