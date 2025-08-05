class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int n;

    void helper(vector<int>& c, int t, int idx, int sum){
        if(sum > t) return;
        if(sum == t){
            ans.push_back(temp);
            return;
        }
        if(idx >= n ) return;

        for(int i=idx; i<n; i++){
            if(i != idx && c[i] == c[i-1]) continue;

            temp.push_back(c[i]);
            helper(c, t, i+1, sum + c[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        n = c.size();
        sort(c.begin(), c.end());
        helper(c, t, 0, 0);
        return ans;
    }
};