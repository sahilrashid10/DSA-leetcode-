class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();

        int count_ones = 0, flips = 0;
        for(auto &c:s){
            if(c == '0'){
                flips = min(flips+1, count_ones);
            }else count_ones++;
        }
        return flips;
    }
};

/* memoization time = O(n), space = O(n)*/
/* recursion time = O(2^n), space = O(n)*/
// class Solution {
// public:
//     int n;
//     vector<vector<int>> dp;
//     int solve(string &s, int i, int p){
//         if(i >= n)  return 0;
        
//         if(dp[i][p] != -1)  return dp[i][p];
//         int flip = INT_MAX, skip = INT_MAX;

//         if(s[i] == '1'){
//             if(p == 1)
//                 skip = solve(s, i+1, 1);
//             else{
//                 flip = 1 + solve(s, i+1, 0);
//                 skip = solve(s, i+1, 1);
//             }      
//         }
//         else {
//             if(p == 0){
//                 flip = 1 + solve(s, i+1, 1);
//                 skip = solve(s, i+1, 0);
//             }
//             else{
//                 flip = 1 + solve(s, i+1, 1);
//             }      
//         }
//         return dp[i][p] = min(flip, skip);
//     }
//     int minFlipsMonoIncr(string s) {
//         n = s.size();
//         if(n == 1)  return 0;

//         dp.resize(n, vector<int>(2, -1));
//         return solve(s, 0, 0);
//     }
// };