class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(grid[m-1][n-1] == 1 || grid[0][0] == 1)  return 0;

        vector<vector<int>> t(m, vector<int>(n, 0));

        for(int i=0; i<n; i++){
            if(grid[0][i] == 1) break;
            t[0][i] = 1;
        }
        for(int i=0; i<m; i++){
            if(grid[i][0] == 1) break;
                t[i][0] = 1;
        }

        for(int i=1; i<m ;i++){
            for(int j=1; j<n; j++){
                if(grid[i][j] != 1)
                    t[i][j] = t[i-1][j] + t[i][j-1];;
            }
        }
        return t[m-1][n-1];
    }
};

// class Solution {
// public:
//     int dp[100][100];
//     vector<pair<int, int>> dir = {{0, 1}, {1, 0}}; // right and down
//     int m, n;
//     int solve(vector<vector<int>> &grid, int i, int j){
//         if(i == m-1 && j == n-1) return 1;
//         if(dp[i][j] != -1) return dp[i][j];

//         int totalPaths = 0;
//         for(auto &[dx, dy] : dir){
//             int x = i + dx, y = j + dy;
//             if(x < m && y < n && grid[x][y] != 1){
//                 totalPaths += solve(grid, x, y);
//             }
//         }
//         dp[i][j] = totalPaths;
//         return totalPaths;
//     }

//     int uniquePathsWithObstacles(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         if(grid[0][0] == 1 || grid[m-1][n-1]) return 0;

//         memset(dp, -1, sizeof(dp));
        
//         return solve(grid, 0, 0);
//     }
// };
 