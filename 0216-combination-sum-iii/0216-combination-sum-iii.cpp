class Solution {
public:
    vector<vector<int>>ans;
    vector<int>sub;
    int lim = 9;
    void solve(int k, int n, int i){

        if(k>lim || n<k) return;

        if(k==0){
            if(n==0)
                ans.push_back(sub);
            return;
        }
        for(int j=i; j<=lim; j++){

            sub.push_back(j);
            solve(k-1, n-j, j+1);
            sub.pop_back();

        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(k, n, 1);
        return ans;
    }
};