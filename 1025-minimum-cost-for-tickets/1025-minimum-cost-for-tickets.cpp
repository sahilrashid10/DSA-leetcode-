class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int d = days.size(), c = costs.size();

        unordered_set<int> s(days.begin(), days.end());
        int maxDays = days[d-1];
        vector<int> dp(maxDays + 1);
        for(int i = 1; i <= maxDays; i++){
            if(s.find(i) == s.end()){
                dp[i] = dp[i-1];
                continue;
            }
            int b1, b7, b30;
            b1 = costs[0] + dp[max(i-1, 0)];

            b7 = costs[1] + dp[max(i-7, 0)];

            b30 = costs[2] + dp[max(i-30, 0)];
            
            dp[i] = min({b1, b7, b30});
        }
        return dp[maxDays];
    }
};


// class Solution {
// public:
//     vector<int> dp;
//     int n, m;
//     int solve(vector<int>& days, vector<int>& costs, int i){
//         if(i >= n)  return 0;
        
//         if(dp[i] != -1) return dp[i];
//         int b1 = INT_MIN, b7 = INT_MIN, b30 = INT_MIN;

//         for(int j=0; j<m; j++){
//             if(j == 0)
//                 b1 = costs[j] + solve(days, costs, i+1);

//             if(j == 1){
//                 int k = i;
//                 while(k<n && days[i] + 7 > days[k]) k++;
//                 b7 = costs[j] + solve(days, costs, k);
//             }
//             if(j == 2){
//                 int k = i;
//                 while(k< n && days[i] + 30 > days[k]) k++;
//                 b30 = costs[j] + solve(days, costs, k);
//             }
//         }
//         return dp[i] = min(b1, min(b7, b30));
//     }
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         n = days.size();
//         m = costs.size();

//         dp.resize(n, -1);
//         return solve(days, costs, 0);
//     }
// };