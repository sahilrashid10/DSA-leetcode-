
class Solution {
public:
    int m = 1e9 + 7;
    int numTilings(int n) {
        if (n == 1 || n == 2)
            return n;
        if (n == 3)
            return 5;

        int nm3 = 1;
        int nm2 = 2;
        int nm1 = 5;
        int ans = 0;
        for (int i = 4; i <= n; i++) {
            ans = (1ll * 2 * nm1 + nm3) % m;
            nm3 = nm2;
            nm2 = nm1;
            nm1 = ans;

        }
        return ans;
    }
};
// class Solution {
// public:
//     int m = 1e9 + 7;
//     int numTilings(int n) {
//         if (n == 1 || n == 2)
//             return n;
//         if (n == 3)
//             return 5;

//         vector<long long> dp(n + 1);
//         dp[1] = 1;
//         dp[2] = 2;
//         dp[3] = 5;
//         for (int i = 4; i <= n; i++) {
//             dp[i] = (2 * dp[i - 1] + dp[i - 3]) % m;
//         }
//         return dp[n];
//     }
// };

// class Solution {
// public:
//     vector<int> dp;
//     int m = 1e9 + 7;
//     int solve(int n) {
//         if (n == 1 || n == 2)
//             return n;
//         if(n == 3)  return 5;
        
//         if(dp[n] != -1) return dp[n];

//         return dp[n] = (2 * solve(n - 1) % m + solve(n - 3) % m) % m;
//     }
//     int numTilings(int n) { 
//         dp.resize(n+1, -1);
//         return solve(n);
//     }
// };