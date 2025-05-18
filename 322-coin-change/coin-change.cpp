class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);  // Fill with "infinity"
        dp[0] = 0;  // Base case: 0 coins needed for amount 0

        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
