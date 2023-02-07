/*
 * @lc app=leetcode id=1210 lang=cpp
 *
 * [1210] Minimum Moves to Reach Target with Rotations
 */

// @lc code=start
#include <map>
#include <queue>
#include <tuple>
#include <vector>
using std::map;
using std::queue;
using std::tuple;
using std::vector;
class Solution {
  public:
    bool is_pos(vector<int> &vec_tmp, vector<vector<int>> &grid, int i) {
        if (i == 0) {
            vec_tmp[1] += 1;
            vec_tmp[3] += 1;
            if (vec_tmp[3] >= grid.size())
                return false;
            else {
                if (grid[vec_tmp[0]][vec_tmp[1]] == 0 && grid[vec_tmp[2]][vec_tmp[3]] == 0)
                    return true;
                else
                    return false;
            }

        } else if (i == 1) {
            vec_tmp[0] += 1;
            vec_tmp[2] += 1;
            if (vec_tmp[2] >= grid.size())
                return false;
            else {
                if (grid[vec_tmp[0]][vec_tmp[1]] == 0 && grid[vec_tmp[2]][vec_tmp[3]] == 0 && vec_tmp[2] < grid.size())
                    return true;
                else
                    return false;
            }

        } else if (i == 2) {
            if (vec_tmp[0] != vec_tmp[2])
                return false;
            else {
                vec_tmp[2] += 1;
                vec_tmp[3] -= 1;
                if (vec_tmp[2] >= grid.size())
                    return false;
                else {
                    if (grid[vec_tmp[2]][vec_tmp[3]] == 0 && grid[vec_tmp[0] + 1][vec_tmp[1] + 1] == 0)
                        return true;
                    else
                        return false;
                }
            }
        } else {
            if (vec_tmp[1] != vec_tmp[3])
                return false;
            else {
                vec_tmp[2] -= 1;
                vec_tmp[3] += 1;
                if (vec_tmp[3] >= grid.size())
                    return false;
                else {
                    if (grid[vec_tmp[2]][vec_tmp[3]] == 0 && grid[vec_tmp[0] + 1][vec_tmp[1] + 1] == 0)
                        return true;
                    else
                        return false;
                }
            }
        }
    }
    int bfs(vector<vector<int>> &grid) {
        int n = grid.size();
        // tuple的第二个元素表示移动次数
        queue<tuple<vector<int>, int>> q; // vec[0],vec[1]表示第一个格子的坐标，vec[2],vec[3]表示第二个格子的坐标
        // 对应四种移动方式的坐标变化
        vector<vector<int>> move{{0, 1, 0, 1}, {1, 0, 1, 0}, {0, 0, 1, -1}, {0, 0, -1, 1}};
        map<vector<int>, int> visited;
        visited[{0, 0, 0, 1}] = 1;
        q.push({{0, 0, 0, 1}, 0});
        while (!q.empty()) {
            auto [vec, cnt] = q.front();
            q.pop();
            // 到达终点
            if (vec[0] == n - 1 && vec[1] == n - 2 && vec[2] == n - 1 && vec[3] == n - 1)
                return cnt;
            for (int i = 0; i < 4; i++) {
                // vector<int> vec_tmp{vec[0] + move[i][0], vec[1] + move[i][1], vec[2] + move[i][2], vec[3] + move[i][3]};
                // if (is_pos(vec_tmp, grid) && visited.find(vec_tmp) == visited.end()) {
                //     q.push({vec_tmp, cnt + 1});
                //     visited[vec_tmp] = 1;
                // }
                auto vec_tmp = vec;
                bool tmp = is_pos(vec_tmp, grid, i);
                if (tmp && visited.find(vec_tmp) == visited.end()) {
                    q.push({vec_tmp, cnt + 1});
                    visited[vec_tmp] = 1;
                }
            }
        }
        return -1;
    }
    int minimumMoves(vector<vector<int>> &grid) {
        int cnt = bfs(grid);
        return cnt;
    }
};
// @lc code=end
