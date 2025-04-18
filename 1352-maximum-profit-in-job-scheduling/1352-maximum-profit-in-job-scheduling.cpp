class Solution {
public:
    int n;
    vector<int> dp;
    int nextJob(vector<vector<int>> &jobInfo, int s, int target){
        int e = n - 1;
        int ans = n;
        while(s <= e){
            int m  = s + (e - s)/2 ;

            if(jobInfo[m][0] >= target){
                ans = m;
                e = m - 1;
            }else{
                s = m + 1;
            }
        }
        return ans;
    }

    int solve(vector<vector<int>> &jobInfo, int i){
        if(i == n)  return 0;
        //memoization
        if(dp[i] != -1) return dp[i];
        //binary search to reduce time(jobIdx[i][1] = endtime of cur job = target)
        int jobIdx = nextJob(jobInfo , i+1, jobInfo[i][1]); 

        int take = jobInfo[i][2] + solve(jobInfo, jobIdx);
        int skip  = solve(jobInfo, i+1);

        return dp[i] = max(take, skip);
    }
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& p) {
        vector<vector<int>> jobInfo;
        for(int i=0; i<p.size(); i++)
            jobInfo.push_back({st[i], et[i], p[i]});

        n = jobInfo.size();
        dp.resize(n, -1);
        sort(jobInfo.begin(), jobInfo.end());

        return solve(jobInfo, 0);
    }
};