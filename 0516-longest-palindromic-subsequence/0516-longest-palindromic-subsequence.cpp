/*  APPROACH 2 BOTTOM UP*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> t(n, vector<int>(n));

        for(int i=0; i<n; i++)
            t[i][i] = 1;
        for(int L = 2; L<=n; L++){
            for(int i=0; L+i-1 < n; i++){
                int j = L+i-1;

                if(s[i] == s[j]) t[i][j] = 2 + t[i+1][j-1];

                else{ 
                    t[i][j] = max(t[i+1][j], t[i][j-1]);
                }
            }
        }
        return t[0][n-1];
    }
};
/*  APPROACH 1 BOTTOM UP*/
// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         int n = s.size();
//         string r = s;
//         reverse(r.begin(), r.end());

//         vector<vector<int>> t(n+1, vector<int>(n+1));
//         for(int i=0; i<=n; i++){
//             for(int j=0; j<=n; j++){

//                 if(i == 0 || j == 0)  t[i][j] = 0;

//                 else if(s[i-1] == r[j-1])   t[i][j] = 1 + t[i-1][j-1];

//                 else{
//                     t[i][j] = max(t[i][j-1], t[i-1][j]);
//                 }
//             }
//         }
//         return t[n][n];
//     }
// };

/*  APPROACH 2*/
// class Solution {
// public: 
//     int dp[1001][1001];
//     int solve(string &s, int i, int j){

//         if(dp[i][j] != -1)  return dp[i][j];
//         if(i > j)    return 0;

//         else if(i == j) return dp[i][j] = 1;

//         else if(s[i] == s[j])
//             return dp[i][j] = 2 + solve(s, i+1, j-1);
        
//         else
//             return dp[i][j] = max(solve(s, i+1, j), solve(s, i, j-1));
        
//         return 0;
//     }
//     int longestPalindromeSubseq(string s) {
//         int n = s.size();
//         memset(dp, -1, sizeof(dp));
//         return solve(s, 0, n-1);
//     }
// };

/*  APPROACH 1*/
// class Solution {
// public:
//     int n;
//     int dp[1000][1000];
//     int lcs(string &s, string &r, int i, int j){
//         if(i == n || j == n) return 0;

//         if(dp[i][j] != -1) return dp[i][j];
//         if(s[i] == r[j]){
//             return dp[i][j] = 1 + lcs(s, r, i+1, j+1);
//         }else{
//             return dp[i][j] = max(lcs(s, r, i+1, j), lcs(s, r, i, j+1));
//         }
//         return 0;
//     }
//     int longestPalindromeSubseq(string s) {
//         n = s.size();
//         memset(dp, -1, sizeof(dp));
//         string r = s;
//         reverse(r.begin(), r.end());

//         return lcs(s, r, 0, 0);
//     }
// };