class Solution {
public:
    vector<int>sub;
    vector<vector<int>>ans;
    void solve(int i, int n, int k){
        if(k==0){
            ans.push_back(sub);
            return;
        }

        for(int j=i; j<=n; j++){
            sub.push_back(j);
            solve(j+1, n, k-1);
            sub.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        solve(1, n, k);
        return ans;
    }
};