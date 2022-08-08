#include <iostream>
#include <unordered_set>
#include <vector>
using std::unordered_set;
using std::vector;
vector<vector<int>> threeSum(vector<int> &nums);
int main() {
    vector<int> nums;
    nums = {-1, 0, 1, 2, -1, -4};
    auto res = threeSum(nums);
    for (auto i : res) {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << "\n";
    }
}
vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int i = 1, j = nums.size() - 1;
    if (nums[0] > 0 || nums[nums.size() - 1] < 0)
        return res;
    for (int k = 0; k < nums.size() - 2; k++) {
        if (k > 0 && nums[k] == nums[k - 1])
            continue;
        i = k + 1;
        j = nums.size() - 1;
        while (i < j) {
            if (nums[k] + nums[i] + nums[j] > 0) {
                j--;
                while (nums[j + 1] == nums[j] && j > i + 1)
                    j--;
            } else if (nums[k] + nums[i] + nums[j] < 0 && i < j - 1)
        }
        while (nums[k] + nums[i] + nums[j] > 0 && i < j - 1) {
            j--;
            while (nums[j + 1] == nums[j] && j > i + 1)
                j--;
        }
        while (nums[k] + nums[i] + nums[j] < 0 && i < j - 1) {
            i++;
            while (nums[i - 1] == nums[i] && i < j - 1)
                i++;
        }
        if (nums[k] + nums[i] + nums[j] == 0) {
            std::cout << "k = " << k << " i = " << i << " j = " << j << "\n";
            res.push_back({nums[k], nums[i], nums[j]});
        }
    }
    return res;
}