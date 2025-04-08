class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (i == j) dp[i][j] = true;  // Single char is always a palindrome
                else if (j == i + 1) dp[i][j] = (s[i] == s[j]);  // Two-char check
                else if (s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = true;

                if (dp[i][j]) count++;
            }
        }

        return count;
    }
};

/*RECURSION + MEMOIZATION  O(n^2)*/
// class Solution {
// public:
//     bool dp[1001][1001];
//     bool isPalindrome(string &s, int i, int j){
//         if(i > j) return true;

//         // if already visietd this state
//         if(dp[i][j] == true) return dp[i][j];

//         if(s[i] == s[j] && isPalindrome(s, i+1, j-1)){
//             return dp[i][j] = true;
//         } 
//         return dp[i][j] = false;
//     }
//     int countSubstrings(string s) {
//         int n = s.size(), count = 0;
//         memset(dp, false, sizeof(dp));

//         for(int i=0; i<n; i++){
//             for(int j=i; j<n; j++){
//                 if(isPalindrome(s, i, j))
//                     count++;
//             }
//         }
//         return count;
//     }
// };