#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> memo;
    int NEG = -1e8;

    int helper(int row1, int col1, int row2, vector<vector<int>>& grid) {
        int col2 = row1 + col1 - row2;
        if (row1 >= n || col1 >= m || row2 >= n || col2 >= m) return NEG;
        
        if (grid[row1][col1] == -1 || grid[row2][col2] == -1) return NEG;

        if(row1==n-1 && col1==m-1) return grid[row1][col1];

        if (memo[row1][col1][row2] != INT_MIN)
            return memo[row1][col1][row2];   

        int picks = grid[row1][col1];
        if (row1 != row2 || col2 != col1) picks += grid[row2][col2];

        int ans = max({
            helper(row1 + 1, col1, row2 + 1, grid),
            helper(row1 + 1, col1, row2, grid),
            helper(row1, col1 + 1, row2, grid),
            helper(row1, col1 + 1, row2 + 1, grid)
        });

        if (ans <= NEG / 2) return memo[row1][col1][row2] = NEG;
        return memo[row1][col1][row2] = ans + picks;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memo.assign(n, vector<vector<int>>(m, vector<int>(n, INT_MIN)));
        return max(0, helper(0, 0, 0, grid)); 
    }
};