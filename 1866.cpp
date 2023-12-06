int dp[1001][1001] = {};
const int mod = 1e9 + 7;
class Solution {
 public:
  int rearrangeSticks(int n, int k) {
    if (k == n) return 1;
    if (k > 0 && n > k && !dp[n][k])
      dp[n][k] = ((long)(n - 1) * rearrangeSticks(n - 1, k) +
                  rearrangeSticks(n - 1, k - 1)) %
                 mod;
    return dp[n][k];
  }
};