#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool dfs(vector<int> &nums, int index, int sum, int target, int cnt, int k, vector<int> &used) {
    if (cnt == k)
        return true;
    if (sum == target) {
        return dfs(nums, index - 1, 0, target, cnt + 1, k, used);
    }

    for (int i = index; i >= 0; i--) {
        if (used[i] || sum + nums[i] > target)
            continue;
        used[i] = 1;
        if (dfs(nums, i - 1, sum + nums[i], target, cnt, k, used))
            return true;
        used[i] = 0;
        if (sum == 0)
            return false;
    }
    return false;
}

int main() {
    int sum = 0;
    vector<int> nums{1, 2, 3};
    int k = 2;
    for (int i : nums)
        sum += i;
    if (sum % k != 0)
        return false;
    std::sort(nums.begin(), nums.end());
    if (nums.back() > sum / k)
        return false;
    vector<int> used(nums.size(), 0);
    dfs(nums, nums.size() - 1, 0, sum / k, 0, k, used);
    return 0;
}