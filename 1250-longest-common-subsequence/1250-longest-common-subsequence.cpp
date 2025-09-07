class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(),
        n2 = text2.size();
        vector<int> prev(n2+1, 0), cur(n2+1, 0);
        for(int i=0; i<n1; i++){
            for(int j = 0; j<n2; j++){
                if(text1[i] == text2[j])
                    cur[j+1] = prev[j] + 1;
                else 
                    cur[j+1] = max(prev[j+1], cur[j]);
            }
            swap(cur, prev);
        }
        return prev[n2];
    }
};

// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n1 = text1.size(),
//         n2 = text2.size();
//         vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
//         for(int i=0; i<n1; i++){
//             for(int j = 0; j<n2; j++){
//                 if(text1[i] == text2[j])
//                     dp[i+1][j+1] = dp[i][j] + 1;
//                 else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
//             }
//         }
//         return dp[n1][n2];
//     }
// };


// class Solution {
// public:
//     vector<vector<int>> dp;
//     int n1, n2;
//     int helper(string &text1, string &text2, int i1, int i2){
//         if(i1 >= n1 || i2 >= n2) return 0;
//         if(dp[i1][i2] != -1) return dp[i1][i2];
//         int take = 0;
//         int skip = 0;
//         if(text1[i1] == text2[i2])
//             take = 1 + helper(text1, text2, i1 + 1, i2 + 1);
//         else{
//             skip = max(
//                 helper(text1, text2, i1 + 1, i2),
//                 helper(text1, text2, i1, i2 + 1)
//             );
//         }
//         return dp[i1][i2] = max(take, skip);
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         n1 = text1.size();
//         n2 = text2.size();
//         dp.resize(n1, vector<int>(n2, -1));
//         return helper(text1, text2, 0, 0);
//     }
// };