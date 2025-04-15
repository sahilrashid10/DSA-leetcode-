class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> t(m, vector<int>(n));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0)    t[0][0] = grid[0][0];
                else if(i == 0) t[i][j] = grid[i][j] + t[i][j-1];
                else if(j == 0) t[i][j] = grid[i][j] + t[i-1][j];
                else{
                    t[i][j] = grid[i][j] + min(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[m-1][n-1];
    }
};
// class Solution {
// public:
//     int m, n;
//     int dp[200][200];

//     int solve(vector<vector<int>>& grid, int i, int j) {
//         if(i >= m || j >= n) return INT_MAX;

//         if(i == m-1 && j == n-1) return grid[i][j];

//         if(dp[i][j] != -1) return dp[i][j];

//         int right = solve(grid, i, j+1);
//         int down = solve(grid, i+1, j);

//         return dp[i][j] = grid[i][j] + min(down, right);
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         memset(dp, -1, sizeof(dp));
//         return solve(grid, 0, 0);
//     }
// };
