/*BOTTOM UP*/

class Solution {
public:
    int minDistance(string &w1, string &w2) {
        int m = w1.size(), n = w2.size();
        if(m == 0 || n == 0) return m+n;

        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                if(i == 0 || j == 0) dp[i][j] = i + j;

                else if(w1[i-1] == w2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
    }
};

/*TOP DOWN - RECURSION AND MEMOIZATION*/
// class Solution {
// public:
//     int dp[501][501];
//     int solve(string &w1, string &w2, int m, int n) {
//         if (m == 0) return n; // insert all remaining from w2
//         if (n == 0) return m; // delete all remaining from w1

//         if(dp[m][n] != -1) return dp[m][n];
//         if (w1[m - 1] == w2[n - 1]) {
//             return dp[m][n] = solve(w1, w2, m - 1, n - 1);
//         } else {
//             // try all 3 operations
//             int insertOp = 1 + solve(w1, w2, m, n - 1);
//             int deleteOp = 1 + solve(w1, w2, m - 1, n);
//             int replaceOp = 1 + solve(w1, w2, m - 1, n - 1);
//             return dp[m][n] = min({insertOp, deleteOp, replaceOp});
//         }
//     }

//     int minDistance(string w1, string w2) {
//         memset(dp, -1, sizeof(dp));
//         return solve(w1, w2, w1.size(), w2.size());
//     }
// };
