class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int len = 1, start = 0;
        for (int L = 1; L <= n; L++) {
            for (int i = 0; L + i - 1 < n; i++) {
                int j = L + i - 1;

                if (i == j)
                    dp[i][j] = true;

                else if (i + 1 == j) {
                    if (s[i] == s[j])
                        dp[i][j] = true;
                } else {
                    if (s[i] == s[j] && dp[i + 1][j - 1] == true)
                        dp[i][j] = true;
                }
                if (dp[i][j] == true) {
                    int temp = j - i + 1;
                    if (len < temp) {
                        len = temp;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, len);
    }
};
//TOP DOWN O(n^2)
// class Solution {
// public:
//     int dp[1001][1001];
//     bool isPalindrome(string &s, int i, int j){
//         if(i > j) return true;

//         if(dp[i][j] != -1) return dp[i][j];

//         if(s[i] == s[j] && isPalindrome(s, i+1, j-1))    return dp[i][j] = true;

//         return dp[i][j] = false;    
//     }
//     string longestPalindrome(string s) {
//         int n = s.size();

//         memset(dp, -1, sizeof(dp));
//         string ans;
//         for(int i=0; i<n; i++){
//             for(int j=i; j<n; j++){
//                 if(isPalindrome(s, i, j)){
//                     int len = j-i+1;

//                     if(len > ans.size())
//                         ans = s.substr(i, len);
//                 }
//             }
//         }
//         return ans;
//     }
// };