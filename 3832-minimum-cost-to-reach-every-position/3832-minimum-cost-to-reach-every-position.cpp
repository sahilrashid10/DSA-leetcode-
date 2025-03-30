class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans(cost.size());
        int m = INT_MAX;
        for(int i=0; i<cost.size(); i++){
            if(cost[i] < m) m = cost[i];
            ans[i] = m;
        }
        return ans;
    }
};