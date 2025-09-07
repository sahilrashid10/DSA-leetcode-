class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int i = 0; i <= m; i++)
            dp[0][i] = i;

        for (int i = 1; i <=n ; i++) {
            for (int j = 1; j <=m ; j++) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];

                else{
                        dp[i][j] = 1 + min({
                        dp[i-1][j-1], 
                        dp[i-1][j],
                        dp[i][j-1]
                    });
                }
            }
        }
        return dp[n][m];
    }
};

// class Solution {
// public:
//     int n;
//     int m;
//     vector<vector<int>> dp;
//     int helper(string &word1, string &word2, int i, int j){
//         if(i == 0 && j == 0) return 0;
//         if(i == 0) return j;
//         if(j == 0) return i;

//         if(dp[i][j] != -1) return dp[i][j];

//         if(word1[i-1] == word2[j-1])
//             return dp[i][j] = helper(word1, word2, i-1, j-1);
//         else{
//             return dp[i][j] = min({
//                 1 + helper(word1, word2, i-1, j), // insert
//                 1 + helper(word1, word2, i, j-1), // delete
//                 1 + helper(word1, word2, i-1, j-1) // replace
//             });
//         }
//     }
//     int minDistance(string word1, string word2) {
//         n = word1.size();
//         m = word2.size();
//         dp.resize(n+1, vector<int>(m+1, -1));
//         return helper(word1, word2, n, m);
//     }
// };