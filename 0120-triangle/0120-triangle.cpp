class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n);

        // last row = same as triangle last row
        for (int c = 0; c < triangle[n-1].size(); c++) {
            prev[c] = triangle[n-1][c];
        }

        // fill DP table from bottom to top
        for (int r = n - 2; r >= 0; r--) {
            vector<int> cur(r+1);
            for (int c = 0; c <= r; c++) {
                cur[c] = triangle[r][c] + min(prev[c], prev[c+1]);
            }
            swap(prev, cur);
        }

        return prev[0]; // top element has the minimum path sum
    }
};

// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n);

//         // initialize DP table with same shape as triangle
//         for (int i = 0; i < n; i++) {
//             dp[i].resize(triangle[i].size());
//         }

//         // last row = same as triangle last row
//         for (int c = 0; c < triangle[n-1].size(); c++) {
//             dp[n-1][c] = triangle[n-1][c];
//         }

//         // fill DP table from bottom to top
//         for (int r = n - 2; r >= 0; r--) {
//             for (int c = 0; c <= r; c++) {
//                 dp[r][c] = triangle[r][c] + min(dp[r+1][c], dp[r+1][c+1]);
//             }
//         }

//         return dp[0][0]; // top element has the minimum path sum
//     }
// };

// class Solution {
// public: 
//     vector<vector<int>> dp;

//     int solve(vector<vector<int>>& triangle, int r, int c) {
//         // invalid col
//         if (c < 0 || c >= triangle[r].size()) return 1e9;

//         // base case: top of the triangle
//         if (r == 0 && c == 0) return triangle[0][0];

//         // memoized
//         if (dp[r][c] != -1) return dp[r][c];

//         // min from above-left or above
//         return dp[r][c] = triangle[r][c] + 
//                           min(solve(triangle, r-1, c), solve(triangle, r-1, c-1));
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         int rows = triangle.size();
//         dp.resize(rows);
//         for (int i = 0; i < rows; i++) {
//             dp[i].assign(triangle[i].size(), -1);
//         }

//         int ans = INT_MAX;
//         // answer = min path to any cell in the last row
//         for (int c = 0; c < triangle[rows-1].size(); c++) {
//             ans = min(ans, solve(triangle, rows-1, c));
//         }
//         return ans;
//     }
// };

// class Solution {
// public: 
//     vector<vector<int>> dp;

//     int solve(vector<vector<int>>& triangle, int r, int c) {
//         if(r == triangle.size()) return 0;  

//         if(dp[r][c] != -1) return dp[r][c];  

//         return dp[r][c] = triangle[r][c] + min(solve(triangle, r+1, c),
//                                                solve(triangle, r+1, c+1));
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         int rows = triangle.size();
//         dp.resize(rows);
//         for(int i = 0; i < rows; i++) {
//             dp[i].assign(triangle[i].size(), -1);  // shape matches triangle
//         }
//         return solve(triangle, 0, 0);
//     }
// };
