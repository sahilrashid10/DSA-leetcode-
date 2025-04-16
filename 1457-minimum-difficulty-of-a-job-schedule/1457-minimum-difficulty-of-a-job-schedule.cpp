class Solution {
public: 
    int dp[301][11];
    int solve(vector<int>& jd, int d, int idx){
        // base case
        
        if(d == 1){
            int maxi = jd[idx];

            for(int i=idx; i<jd.size(); i++){
                maxi = max(maxi, jd[i]);
            }
            return dp[idx][d] = maxi;
        }

        if(dp[idx][d] != -1)    return dp[idx][d];
        
        int maxi = INT_MIN;
        int result = INT_MAX;

        for(int i=idx; i <= jd.size() - d; i++){
            maxi = max(maxi, jd[i]);

            int temp = maxi + solve(jd, d-1, i+1);

            result = min(result, temp);
        }
        return dp[idx][d] = result;
    }
    int minDifficulty(vector<int>& jd, int d) {
        if(jd.size() < d)   return -1;

        memset(dp, -1, sizeof(dp));

        return solve(jd, d, 0);
    }
};