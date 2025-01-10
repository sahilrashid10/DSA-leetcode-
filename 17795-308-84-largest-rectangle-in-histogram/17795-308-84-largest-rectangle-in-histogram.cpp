class Solution {
public:
    vector<int> findNSL(const vector<int>& h){
        stack<int>s;
        vector<int>ans(h.size());
        for(int i=0; i<h.size(); i++){
            while(!s.empty() && h[s.top()]>=h[i])
                s.pop();
            ans[i] = s.empty()?-1:s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> findNSR(const vector<int>& h){
        stack<int>s;
        vector<int>ans(h.size());
        for(int i=h.size()-1; i>=0; i--){
            while(!s.empty() && h[s.top()]>h[i])
                s.pop();
            ans[i] = s.empty()?h.size():s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& h) {
        if(h.size()==0)
            return h[0];
        int max_area = 0;
        vector<int>NSL = findNSL(h);
        vector<int>NSR = findNSR(h);
        for(int i=0; i<h.size(); i++){
            // int l=i-NSL[i];
            // int r=NSR[i]-i;
            // int total_len = l+r-1;
            // int area_hist = total_len * h[i];
            max_area = max(max_area, (NSR[i]-NSL[i]-1)*h[i]);
        }
        return max_area;
    }
};