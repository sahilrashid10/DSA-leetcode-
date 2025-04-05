/*BOTTOM UP*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<dp.size(); i++){
            for(int j=1; j<dp[0].size(); j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
/*TOP DOWN (MEMOIZATION) 1 46/47 TC PASS*/
// class Solution {
// public:
//     int n, m;
//     vector<vector<int>>dp;
//     int solve(string t1, string t2, int i, int j){
//         if(i >= n || j >= m) return 0;
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int take = 0, skip = 0;
//         if(t1[i] == t2[j]) 
//             take = 1 + solve(t1, t2, i+1, j+1);
//         else{
//             int sk1 = solve(t1, t2, i+1, j);
//             int sk2 = solve(t1, t2, i, j+1);
//             take = max(sk1, sk2);
//         }
//         return dp[i][j] = max(take, skip);
//     }
//     int longestCommonSubsequence(string t1, string t2) {
//         n = t1.size();
//         m = t2.size();
//         dp.resize(1000, vector<int>(1000, -1));

//         return solve(t1, t2, 0, 0);
//     }
// };