#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location) {
    vector<float> point_angle(points.size(), 0);
    for (int i = 0; i < points.size(); i++) {
        if (points[i][0] == location[0]) {
            if (points[i][1] > location[1])
                point_angle[i] = 90;
            else if (points[i][1] == location[1])
                point_angle[i] = 361; // 用来标记这是一个重叠的点
            else
                point_angle[i] = -90;
        } else {
            point_angle[i] = atan2(points[i][1] - location[1], points[i][0] - location[0]) * 180 / M_PI;
        }
    }
    int ans = 0;
    std::sort(point_angle.begin(), point_angle.end());
    for (int i = point_angle.size() - 1; i >= 0; i--) {
        if (point_angle[i] > 360) {
            point_angle.pop_back();
            ans++;
        }
    }

    int l = 0;
    ans++;

    for (int r = 1; r < point_angle.size(); r++) {
        if (point_angle[r] - point_angle[l] > angle)
            while (l < point_angle.size() && point_angle[r] - point_angle[l] > angle)
                l++;
        else
            ans = max(ans, r - l + 1);
    }
    return ans;
}

int main() {
    vector<vector<int>> points{{0, 0}, {0, 2}};
    int angle = 90;
    vector<int> location{1, 1};

    int res = visiblePoints(points, angle, location);
    return res;
}