class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    int n;
    void solve(vector<int>& c, int k, int i, int sum){
        if(sum == k){
            result.push_back(temp);
            return;
        }
        if(i == n || sum > k){
            return;
        }

        temp.push_back(c[i]);
        solve(c, k, i, sum+c[i]);
        temp.pop_back();
        solve(c, k, i+1, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int k) {
        n = c.size();
        solve(c, k, 0, 0);
        return result;
    }
};