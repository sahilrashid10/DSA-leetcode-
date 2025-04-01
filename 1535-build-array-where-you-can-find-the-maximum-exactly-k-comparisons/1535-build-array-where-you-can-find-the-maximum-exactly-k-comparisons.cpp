// MEMOIZED APPROACH
class Solution {
public:

    int dp[50][101][51];
    int mod = 1e9+7;
    int solve(int n, int m, int k, int idx, int maxi, int op){

        //base case
        if(idx == n){
            if(op == k) return 1;
            return 0;
        }

        if(maxi != -1 && dp[idx][maxi][op] != -1) return dp[idx][maxi][op];

        int result = 0;
        for(int i=1; i<=m; i++){
            if(maxi < i){
                result = (result + solve(n, m, k, idx+1, i, op+1))%mod;
            }else
                result = (result + solve(n, m, k, idx+1, maxi, op))%mod;
        }

        if(maxi != -1){
            dp[idx][maxi][op] = result;
        }
        return result;

    }
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(n, m, k, 0, -1, 0);
        return ans;
    }
};