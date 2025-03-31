/**BOTTOM UP O(N^2) TIME AND SPACE O(N)**/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        if(n == 1) return 1;
        sort(begin(pairs), end(pairs));
        vector<int> dp(n, 1);

        int maxi = 1;
        for(int i = 1; i<n; i++){
            int j = 0;
            while(j < i){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[j]+1, dp[i]);
                    maxi = max(maxi, dp[i]);
                }
                j++;
            }
        }
        return maxi;
    }
};

/**MEMOIZATION AND RECURSION O(N^2) SPACE AND TIME**/
// class Solution {
// public:
//     int n;
//     int dp[1000][1000];
//     int solve(vector<vector<int>>& pairs, int i, int p){
//         if(i >= n) return 0;

//         if(p!= -1 && dp[i][p] != -1) return dp[i][p];
//         int take = 0;
//         if(p == -1 ||  pairs[p][1] < pairs[i][0])
//             take = 1 + solve(pairs, i+1, i);

//         int skip = solve(pairs, i+1, p);

//         if(p != -1) dp[i][p] = max(take, skip);

//         return max(take, skip);
//     }
//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(), pairs.end());
//         memset(dp, -1, sizeof(dp));
//         n = pairs.size();
//         int ans = solve(pairs, 0, -1);
//         return ans;
//     }
// };