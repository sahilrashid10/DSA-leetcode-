class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;

    void helper(vector<int>& c, int &t, int i, int sum){
        if(i == c.size()) return;

        if(sum > t) return;
        else if(sum == t){
            ans.push_back(temp);
            return;
        }
        sum += c[i];
        temp.push_back(c[i]);
        helper(c, t, i, sum);
        
        sum -= c[i];
        temp.pop_back();
        helper(c, t, i+1, sum);

    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) { 
        helper(c, t, 0, 0);
        return ans;
    }
};