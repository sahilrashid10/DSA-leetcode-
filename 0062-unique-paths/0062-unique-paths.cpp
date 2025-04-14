class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m, vector<int>(n, 1));

        for(int i=0; i<m ;i++){
            for(int j=0; j<n; j++){
                if(i>0 && j>0){
                    t[i][j] = t[i-1][j] + t[i][j-1];
                }
            }
        }
        return t[m-1][n-1];
    }
};

// class Solution {
// public:
//     int dp[100][100];
//     vector<pair<int, int>> dir = {{0, 1}, {1, 0}}; // right and down

//     int solve(int m, int n, int i, int j){
//         if(i == m-1 && j == n-1) return 1;
//         if(dp[i][j] != -1) return dp[i][j];

//         int totalPaths = 0;
//         for(auto &[dx, dy] : dir){
//             int x = i + dx, y = j + dy;
//             if(x < m && y < n){
//                 totalPaths += solve(m, n, x, y);
//             }
//         }
//         dp[i][j] = totalPaths;
//         return totalPaths;
//     }

//     int uniquePaths(int m, int n) {
//         memset(dp, -1, sizeof(dp));
//         return solve(m, n, 0, 0);
//     }
// };
