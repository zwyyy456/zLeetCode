/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 */

// @lc code=start
#include <queue>
#include <tuple>
#include <vector>
using std::queue;
using std::tuple;
using std::vector;
class Solution {
  public:
    void bfs(queue<tuple<int, int, int>> q, vector<vector<int>> &red_connect, vector<vector<int>> &blue_connect, vector<int> &answer, int n, int i) {
        vector<vector<int>> visited(n, vector<int>(2, 0)); // visited[k][1]表示由红到point，visited[k][0]为1表示由蓝到point
        int tmp_point = 0;
        while (!q.empty()) {
            auto [point, len, c_flag] = q.front();
            visited[point][c_flag] = 1;
            q.pop();
            if (answer[point] == -1)
                answer[point] = len;
            else
                answer[point] = min(answer[point], len);
            if (c_flag == 0) {
                for (int k = 0; k < red_connect[point].size(); k++) {
                    tmp_point = red_connect[point][k];
                    if (visited[tmp_point][1] != 1)
                        q.push({tmp_point, len + 1, 1});
                }
            } else {
                for (int k = 0; k < blue_connect[point].size(); k++) {
                    tmp_point = blue_connect[point][k];
                    if (visited[tmp_point][0] != 1)
                        q.push({tmp_point, len + 1, 0});
                }
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) {
        vector<vector<int>> red_connect(n);
        vector<vector<int>> blue_connect(n);
        for (auto &vec : redEdges) {
            red_connect[vec[0]].push_back(vec[1]);
        }
        for (auto &vec : blueEdges) {
            blue_connect[vec[0]].push_back(vec[1]);
        }
        vector<int> answer(n, -1);
        answer[0] = 0;
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 0});
        q.push({0, 0, 1});
        bfs(q, red_connect, blue_connect, answer, n, 0);
        return answer;
    }
};
// @lc code=end
