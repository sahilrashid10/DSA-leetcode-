class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        using ll = long long;
        vector<ll> dp(n+1, LLONG_MAX);
        dp[0] = 0;

        for(int i=0; i<n; i++){
            if(dp[i] == LLONG_MAX) continue;

            if(i+3 <=n){
                ll costJump = 1LL * (i+3-i) *(i+3-i);
                ll costSum = dp[i]+costs[i+3-1] + costJump;
                dp[i+3] = min(dp[i+3], costSum);
            }
            if(i+2 <=n){
                ll costJump = 1LL * (i+2-i) *(i+2-i);
                ll costSum = dp[i]+costs[i+2-1] + costJump;
                dp[i+2] = min(dp[i+2], costSum);
            }
            if(i+1 <=n){
                ll costJump = 1LL * (i+1-i) *(i+1-i);
                ll costSum = dp[i]+costs[i+1-1] + costJump;
                dp[i+1] = min(dp[i+1], costSum);
            }
        }
        return dp[n];
    }
};