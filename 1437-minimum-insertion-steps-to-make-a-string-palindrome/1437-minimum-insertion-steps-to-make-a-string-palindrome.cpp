/*BOTTOM UP*/
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        
        vector<vector<int>> t(n, vector<int>(n));

        for(int L = 2; L<=n; L++){
            for(int i=0;  L + i - 1 < n; i++){
                int j = L + i - 1;

                if(i + 1 == j && s[i] != s[j]) t[i][j] = 1;
                else if(s[i] == s[j])   t[i][j] = t[i+1][j-1];
                else
                    t[i][j] = 1 + min(t[i+1][j], t[i][j-1]);
            }
        }
        return t[0][n-1];
    }
};
/*TOP DOWN  - MEMOIZATION*/
// class Solution {
// public:

//     int n;
//     int dp[500][500];
//     int solve(string &s, int i, int j){
//         if(i >= j)   return 0;
        
//         if(dp[i][j] != -1)   return dp[i][j];
//         int take = 0, skip = 0;
//         if(s[i] == s[j])
//             take = solve(s, i+1, j-1);
//         else
//             skip = 1 + min(solve(s, i, j - 1), solve(s, i+1, j));

//         return dp[i][j] = max(skip, take);
//     }
//     int minInsertions(string s) {
//         int n = s.size();

//         memset(dp, -1, sizeof(dp));
//         return solve(s, 0, n-1);
//     }
// };