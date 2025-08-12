class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>s;   
        int n = t.size();
        
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && t[i] >= t[s.top()]){
                s.pop();
            }
            int top = s.empty() ? 0 : s.top()-i;
            ans[i] = top;
            s.push(i);
        }
        return ans;
    }
};