class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int n = s.size();
        sort(s.begin(), s.end());
        vector<long long> prev(n+1,  INT_MIN);

        //base case
        prev[0] = 0;
        prev[1]= s[0];

        for(int i=1; i<n; i++){
            for(int t = n; t>=1; t--){
                long long take = 1ll*t* s[i] + prev[t-1];
                long long skip = prev[t];

                prev[t] = max(take, skip);
            }
        }
        return *max_element(prev.begin(), prev.end());
    }
};

// class Solution {
// public:
//     int maxSatisfaction(vector<int>& s) {
//         int n = s.size();
//         sort(s.begin(), s.end());
//         vector<long long> prev(n+1,  INT_MIN), cur(n+1,  INT_MIN);

//         //base case
//         prev[0] = 0;
//         cur[0] = 0;
//         prev[1]= s[0];

//         for(int i=1; i<n; i++){
//             for(int t = 1; t<=n; t++){
//                 long long take = t * s[i] + prev[t-1];
//                 long long skip = prev[t];

//                 cur[t] = max(take, skip);
//             }
//             prev = cur;
//         }
//         return *max_element(prev.begin(), prev.end());
//     }
// };


// class Solution {
// public:
//     int maxSatisfaction(vector<int>& s) {
//         int n = s.size();
//         vector<vector<long long>> dp(n, vector<long long>(n+1,  INT_MIN));
//         sort(s.begin(), s.end());

//         //base case
//         for(int i=0; i < n; i++)
//             dp[i][0] = 0;
        
//         dp[0][1] = s[0];

//         for(int i=1; i<n; i++){
//             for(int t = 1; t<=n; t++){
//                 long long take = t * s[i] + dp[i-1][t-1];
//                 long long skip = dp[i-1][t];

//                 dp[i][t] = max(take, skip);
//             }
//         }
//         return *max_element(dp[n-1].begin(), dp[n-1].end());
//     }
// };

// class Solution {
// public:
//     int n;
//     vector<vector<int>> dp;
//     int solve(vector<int>& s, int i, int time){
//         if(i >= n)  return 0;

//         if(dp[i][time] != -1) return dp[i][time]; 
//         int take = time * s[i] + solve(s, i+1, time + 1);
//         int skip = solve(s, i+1, time);

//         return dp[i][time] = max(take, skip);
//     }   
//     int maxSatisfaction(vector<int>& s) {
//         sort(s.begin(), s.end());
//         n = s.size();
//         dp.resize(n, vector<int>(n+1, -1));
//         return solve(s, 0, 1);
//     }
// };