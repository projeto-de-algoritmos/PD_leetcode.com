class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int dp[amount + 1];
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      dp[i] = __INT_MAX__;
      for (int c : coins) {
        if (i - c >= 0 && dp[i - c] != __INT_MAX__) {
          dp[i] = min(dp[i], 1 + dp[i - c]);
        }
      }
    }
    return dp[amount] == __INT_MAX__ ? -1 : dp[amount];
  }
};