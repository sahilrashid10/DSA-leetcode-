class Solution {
public:

    void solve(vector<int>&c, int k, int n,vector<vector<int>>&ans, vector<int>&s,
     int sum, int i)
    {
        if(sum == k){
            ans.push_back(s);
            return;
        }
        if(i>=n || sum>k) return;

        sum += c[i];
        s.push_back(c[i]);
        solve(c, k, n,ans, s, sum, i);
        sum -= c[i];
        s.pop_back();
        solve(c, k, n,ans, s, sum, i+1);
        return ;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>subset;
        vector<vector<int>>ans;
        solve(candidates, target, candidates.size(), ans, subset, 0, 0);
        return ans;
    }
};