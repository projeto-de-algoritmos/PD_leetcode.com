class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        const int INF = 1e9;
        vector<int> d(n + 1, INF);
        d[0] = -INF;
        for (int i = 0; i < n; i++) {
            int l = upper_bound(d.begin(), d.end(), nums[i]) - d.begin();
            if (d[l - 1] < nums[i] && nums[i] < d[l]) {
                d[l] = nums[i];
            }
        }
        int ans = 0;
        for (int l = 0; l <= n; l++) {
            if (d[l] < INF) {
                ans = l;
            }
        }
        return ans;
    }
};