#include <vector>
using std::vector;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> my_coins(coins.size() + 1, 0);
        for (int i = 0; i < coins.size(); i++) {
            my_coins[i + 1] = coins[i];
        }
        // vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        // dp[0][0] = 1;
        // for (int i = 1; i <= coins.size(); i++) {
        //     for (int j = 0; j <= amount; j++) {
        //         dp[i][j] = dp[i - 1][j];
        //         int tmp = j;
        //         while (tmp >= my_coins[i]) {
        //             dp[i][j] += dp[i - 1][tmp - my_coins[i]];
        //             tmp -= my_coins[i];
        //         }
        //     }
        // }
        // return dp[coins.size()][amount];
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= coins.size(); i++) {
            for (int j = amount; j >= my_coins[i]; j--) {
                int tmp = j;
                while (tmp >= my_coins[i]) {
                    dp[j] += dp[tmp - my_coins[i]];
                    tmp -= my_coins[i];
                }
            }
        }
        return dp[amount];
    }
};