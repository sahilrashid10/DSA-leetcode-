// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int n;
//         int m;
//         vector<vector<int>> dp(n, vector<int>(m, 0)));

//         for(int i=0; i<n; i++){
//             for(int j = 0; j<m; j++){
//                 if(word1[i] == word2[j])
//                     continue;
                
//                 dp[i+1][j+1] = min({
//                     1 + dp[i+1][j+1]
//                 });
//             }
//         }

//     }
// };


class Solution {
public:
    int n;
    int m;
    vector<vector<int>> dp;
    int helper(string &word1, string &word2, int i, int j){
        if(i < 0 && j < 0) return 0;
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j])
            return dp[i][j] = helper(word1, word2, i-1, j-1);
        else{
            return dp[i][j] = min({
                1 + helper(word1, word2, i-1, j), // insert
                1 + helper(word1, word2, i, j-1), // delete
                1 + helper(word1, word2, i-1, j-1) // replace
            });
        }
    }
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        dp.resize(n, vector<int>(m, -1));
        return helper(word1, word2, n-1, m-1);
    }
};