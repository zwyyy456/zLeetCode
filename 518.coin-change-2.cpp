#include <iostream>
#include <vector>
using std::vector;

// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         vector<int> my_coins(coins.size() + 1, 0);
//         for (int i = 0; i < coins.size(); i++) {
//             my_coins[i + 1] = coins[i];
//         }
//         vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
//         dp[0][0] = 1;
//         for (int i = 1; i <= my_coins.size(); i++) {
//             for (int j = 1; j <= amount; j++) {
//                 dp[i][j] = dp[i - 1][j];
//                 int tmp = j;
//                 while (j >= my_coins[i]) {
//                     dp[i][j] += dp[i - 1][j - my_coins[i]];
//                     j -= my_coins[i];
//                 }
//                 j = tmp;
//             }
//         }
//         return dp[my_coins.size()][amount];
//     }
// };

int change(int amount, vector<int> &coins) {
    vector<int> my_coins(coins.size() + 1, 0);
    for (int i = 0; i < coins.size(); i++) {
        my_coins[i + 1] = coins[i];
    }
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
    dp[0][0] = 1;
    int tmp = 0;
    for (int i = 1; i <= coins.size(); i++) {
        for (int j = 0; j <= amount; j++) {
            dp[i][j] = dp[i - 1][j];
            tmp = j;
            while (j >= my_coins[i]) {
                dp[i][j] += dp[i - 1][j - my_coins[i]];
                j -= my_coins[i];
            }
            j = tmp;
        }
    }
    for (int i = 1; i <= coins.size(); i++) {
        for (int j = 0; j <= amount; j++)
            std::cout << dp[i][j] << " ";
        std::cout << "\n";
    }
    return 0;
}

int main() {
    vector<int> coins{1, 2, 5};
    int a = change(5, coins);
    return 0;
}