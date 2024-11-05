class Solution {
public:
    vector<vector<int>>ans;
    vector<int>sub;

    void solve(vector<int>&candi, int k, int i){
        if(k==0){
            ans.push_back(sub);
            return;
        }
        if(k<0) return;

        for(int j=i; j<candi.size(); j++){
            //back-tracking:controlled recursion "condition".
            if(j>i && candi[j] == candi[j-1])
            continue;

            sub.push_back(candi[j]);

            solve(candi, k-candi[j], j+1);

            sub.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return ans; 
    }
};