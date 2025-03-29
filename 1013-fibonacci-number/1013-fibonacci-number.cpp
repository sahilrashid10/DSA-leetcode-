//using dp, bottom up
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        
        vector<int> dp(n+1, -1);
        dp[0] = 0, dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
// using dp-top down, recursion
// class Solution {
// public:
//     int solve(int n, vector<int> &dp) {
//         if( n <= 1) return n;

//         if(dp[n] != -1) return dp[n];

//         return dp[n] = fib(n-1) + fib(n-2);
//     }
//     int fib(int n) {
//         vector<int> dp(n+1, -1);
//         int fib_n = solve(n, dp);
//         return fib_n;
//     }
// };