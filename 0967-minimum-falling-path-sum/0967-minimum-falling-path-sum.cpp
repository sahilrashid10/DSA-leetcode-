class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();

        vector<int> prevRow(col);

        for(int j=0; j<col; j++)
            prevRow[j] = matrix[0][j];

        vector<pair<int, int>> dir{{-1, -1}, {-1, 0}, {-1, 1}};
        for(int i = 1; i<row; i++){
            vector<int>dp(col, INT_MAX);

            for(int j=0; j<col; j++){
                for(auto &[dx, dy]:dir){
                    int x = i + dx, y = j + dy;
                    if(x >=0 && y < col && y>=0)
                        dp[j] = min(dp[j], prevRow[y] + matrix[i][j]);
                }
            }
            prevRow = dp;
        }
        return *min_element(prevRow.begin(), prevRow.end());
    }
};


// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int row = matrix.size(), col = matrix[0].size();

//         vector<vector<int>> dp(row, vector<int>(col, INT_MAX));

//         for(int j=0; j<col; j++)
//             dp[0][j] = matrix[0][j];

//         vector<pair<int, int>> dir{{-1, -1}, {-1, 0}, {-1, 1}};
//         for(int i = 1; i<row; i++){
//             for(int j=0; j<col; j++){
                
//                 for(auto &[dx, dy]:dir){
//                     int x = i + dx, y = j + dy;
//                     if(x >=0 && y < col && y>=0)
//                         dp[i][j] = min(dp[i][j], dp[x][y] + matrix[i][j]);
//                 }
//             }
//         }
//         return *min_element(dp[row-1].begin(), dp[row-1].end());
//     }
// };



// class Solution {
// public:
//     int row, col;
//     vector<pair<int, int>> dir = {{1, -1}, {1, 0}, {1, 1}};
//     vector<vector<int>> dp;
//     int solve(vector<vector<int>>& matrix, int i, int j){
//         if(i<0 || j<0|| j == col)    return INT_MAX;

//         if(i == row-1){
//             return matrix[i][j];
//         } 
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
//         int result = INT_MAX;
//         for(auto &[dx, dy]:dir){
//             int x = i + dx, y = j + dy;
//             result = min(result, solve(matrix, x, y));
//         }
//         return dp[i][j] = matrix[i][j] + result;
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         row = matrix.size();
//         col = matrix[0].size();
//         int ans = INT_MAX;

//         dp.resize(row+1, vector<int>(col+1, -1));
//         // i- ith row, j- jth column
//         for(int j=0; j<col; j++){
//             ans = min(ans, solve(matrix, 0, j));
//         }
//         return ans;
//     }
// };






// int solve(vector<vector<int>>& matrix, int i, int j, int sum) {
//     if (i < 0 || j < 0 || j >= col) return INT_MAX;

//     if (i == row - 1) return sum;

//     int result = INT_MAX;
//     for (auto &[dx, dy] : dir) {
//         int x = i + dx, y = j + dy;
//         if (x >= 0 && x < row && y >= 0 && y < col)
//             result = min(result, solve(matrix, x, y, sum + matrix[x][y]));
//     }

//     return result;
// }
